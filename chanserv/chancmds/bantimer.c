/* Automatically generated by refactor.pl.
 *
 *
 * CMDNAME: bantimer
 * CMDLEVEL: QCMD_AUTHED
 * CMDARGS: 2
 * CMDDESC: Shows or changes the time after which bans are removed.
 * CMDFUNC: csc_dobantimer
 * CMDPROTO: int csc_dobantimer(void *source, int cargc, char **cargv);
 * CMDHELP: Usage: BANTIMER <channel> [<duration>]
 * CMDHELP: To help keep channels clear of the clutter of too many bans, Q can automatically
 * CMDHELP: remove channel bans after a specified time.  This command is used to alter that
 * CMDHELP: time period, disable the feature, or show the current setting, where:
 * CMDHELP: channel  - the channel to use
 * CMDHELP: duration - how long to remove channel bans after.  If duration is 0 then channel
 * CMDHELP:            bans will not be automatically removed.  If duration is not specified,
 * CMDHELP:            the current setting will be displayed.  Suffixes can m (minutes), 
 * CMDHELP:            h (hours), d (days), w (weeks), M (months) and y (years) can be used 
 * CMDHELP:            to specify the duration, for example 3d, 1w, 1h30m.
 * CMDHELP: Viewing the current setting requires operator (+o) access on the named channel.
 * CMDHELP: Changing the setting requires master (+m) access on the named channel.
 */

#include "../chanserv.h"
#include "../../nick/nick.h"
#include "../../lib/flags.h"
#include "../../lib/irc_string.h"
#include "../../channel/channel.h"
#include "../../parser/parser.h"
#include "../../irc/irc.h"
#include "../../localuser/localuserchannel.h"
#include <string.h>
#include <stdio.h>

int csc_dobantimer(void *source, int cargc, char **cargv) {
  nick *sender=source;
  chanindex *cip;
  regchan *rcp;
  int oldtimer;

  if (cargc<1) {
    chanservstdmessage(sender, QM_NOTENOUGHPARAMS, "bantimer");
    return CMD_ERROR;
  }

  if (!(cip=cs_checkaccess(sender, cargv[0], CA_OPPRIV, NULL, "bantimer",
			   QPRIV_VIEWBANTIMER, 0)))
    return CMD_ERROR;

  rcp=cip->exts[chanservext];

  if (cargc>1) {
    if (!cs_checkaccess(sender, NULL, CA_MASTERPRIV, cip, "bantimer",
			QPRIV_CHANGEBANTIMER, 0))
      return CMD_ERROR;

    oldtimer=rcp->banduration;
    rcp->banduration=durationtolong(cargv[1]);

    if (rcp->banduration<=0) {
      if(strcmp(cargv[1], "0")) {
        rcp->banduration=oldtimer;
        chanservstdmessage(sender, QM_INVALIDDURATION2, cargv[1]);
        return CMD_ERROR;
      }
      rcp->banduration=0;
    }
    
    /* Arbitrary limit */
    if (rcp->banduration > 31622400)
      rcp->banduration = 31622400;
      
    csdb_updatechannel(rcp);
    
    cs_log(sender,"BANTIMER %s %s (%u -> %lu)",cip->name->content,cargv[1],oldtimer,rcp->banduration);
    chanservstdmessage(sender, QM_DONE);
    cs_timerfunc(cip);
  }

  if (rcp->banduration)
    chanservstdmessage(sender, QM_CHANBANAUTOREMOVE, cargv[0], longtoduration(rcp->banduration, 1));
  else
    chanservstdmessage(sender, QM_NOCHANBANAUTOREMOVE, cargv[0]);

  return CMD_OK;
}
