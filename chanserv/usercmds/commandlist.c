/* Automatically generated by mkcommandlist.pl, do not edit. */

#include "../chanserv.h"

/* Prototypes */
int csa_doaccounthistory(void *source, int cargc, char **cargv);
int csu_docleanupdb(void *source, int cargc, char **cargv);
int csu_dodeluser(void *source, int cargc, char **cargv);
int csu_dodomainmode(void *source, int cargc, char **cargv);
int csu_doinfo(void *source, int cargc, char **cargv);
int csu_dolanguage(void *source, int cargc, char **cargv);
int csu_dolistflags(void *source, int cargc, char **cargv);
int csu_domaillock(void *source, int cargc, char **cargv);
int csa_dorollbackaccount(void *source, int cargc, char **cargv);
int csu_dospewdb(void *source, int cargc, char **cargv);
int csu_dospewdomain(void *source, int cargc, char **cargv);
int csu_dospewemail(void *source, int cargc, char **cargv);
int csu_dospewpass(void *source, int cargc, char **cargv);
int csu_dosuspenduser(void *source, int cargc, char **cargv);
int csu_dosuspenduserlist(void *source, int cargc, char **cargv);
int csu_dounsuspenduser(void *source, int cargc, char **cargv);
int csu_dousercomment(void *source, int cargc, char **cargv);
int csu_douserflags(void *source, int cargc, char **cargv);
int csu_dowhoami(void *source, int cargc, char **cargv);
int csu_dowhois(void *source, int cargc, char **cargv);
void usercmds_init(void);
void usercmds_fini(void);


void _init() {
  usercmds_init();
  chanservaddcommand("accounthistory", QCMD_OPER, 1, csa_doaccounthistory, "View password/email history for an account.", "Usage: accounthistory <account>\nShows password/email history for the specified account.\n");
  chanservaddcommand("cleanupdb", QCMD_DEV, 0, csu_docleanupdb, "Clean up database.", "Usage: cleanupdb\nCleans up inactive accounts, unused accounts and inactive channels.\n");
  chanservaddcommand("deluser", QCMD_OPER, 2, csu_dodeluser, "Removes a user from the bot.", "Usage: deluser <username>\nRemoves the specified username from the bot.\n");
  chanservaddcommand("domainmode", QCMD_OPER, 4, csu_dodomainmode, "Set/Unset Mail Domain Modes", "Usage: domainmode <domain> [<flags>]\nViews or modifies the domainmode flags for specified domain.\nFlags consist of:\n  +b          don't allow email addresses from this domain.\n  +u <limit>  don't allow more than <limit> accounts to share\n              email addresses on this domain.\n  +l <limit>  don't allow more than <limit> accounts with\n              email addresses on this domain.\nNote that domains are hierarchical, so setting +b on org will\nprevent operations from quakenet.org, fish.quakenet.org, etc.\n");
  chanservaddcommand("info", QCMD_AUTHED | QCMD_OPER, 2, csu_doinfo, "Shows or changes info line.", "Usage: INFO [<channel>] [<info line>]\nShows or updates your current info line, which can be configured to be displayed\nwhen you join a channel.  Where:\nchannel   - channel to set info line on.  If no channel is specified, your default\n            info line will be used.  If a channel is specified you must be known\n            (+k) on the channel.\ninfo line - new info line to set.  If not specified, the current info line will be\n            displayed.  If \"none\" is specified, the info line will be cleared.\n");
  chanservaddcommand("language", QCMD_AUTHED | QCMD_OPER, 1, csu_dolanguage, "Shows or changes your current language.", "Usage: language [<language code>]\nShows your currently selected language and a list of others\nby default, changes your language when you specify a language code.\n");
  chanservaddcommand("listflags", QCMD_OPER, 1, csu_dolistflags, "List users with the specified user flags.", "Usage: listflags <flags>\nShows a list of all users with the specified user flags.\n");
  chanservaddcommand("maillock", QCMD_OPER, 3, csu_domaillock, "Set/unset/list mail lock patterns", "Usage: maillock <-list|-add|-del> <pattern> [<reason>]\nManipulates the list of mail lock patterns.\nAny email address matching the pattern will be refused in HELLO/EMAIL.\nA reason is optional for -list, but recommended.\n");
  chanservaddcommand("rollbackaccount", QCMD_OPER, 2, csa_dorollbackaccount, "Roll back password/email changes on an account.", "Usage: rollbackaccount <username> <duration>\nRolls back an account to a previous point, reverting password and email changes.\n");
  chanservaddcommand("spewdb", QCMD_OPER, 1, csu_dospewdb, "Search for a user in the database.", "Usage: spewdb <pattern>\nDisplays all users with usernames that match the specified pattern.\n");
  chanservaddcommand("spewdomain", QCMD_OPER, 1, csu_dospewdomain, "Spew Mail Domains.", "Usage: spewdomain <pattern>\nDisplays all mail domains that match the specified pattern.\n");
  chanservaddcommand("spewemail", QCMD_OPER, 1, csu_dospewemail, "Search for an e-mail in the database.", "Usage: spewdb <pattern>\nDisplays all users with email addresses that match the supplied pattern.\n");
  chanservaddcommand("spewpass", QCMD_OPER, 1, csu_dospewpass, "Search for a password in the database.", "Usage: spewpass <pattern>\nDisplays all users with a password that matches the specified pattern.\n");
  chanservaddcommand("suspenduser", QCMD_OPER, 1, csu_dosuspenduser, "Suspend/Delay GLINE/Instantly GLINE a user.", "Usage: suspenduser <username> [<duration>] <reason>\n                   -nokill <username> [<duration>] <reason>\n                   -gline <username> [<duration>] <reason>\n                   -instantgline <username> [<duration>] <reason>\n                   -password <password> [<duration>] <reason>\n                   -email <email address> [<duration>] <reason>\nSuspends one or more users, either based on username, email\naddress or password.\nBy default the user will be immediately disconnected unless\nnokill is specified.\ngline will gline the user at some random period of time after\nthey auth, instantgline will gline them the moment they auth.\n");
  chanservaddcommand("suspenduserlist", QCMD_HELPER, 1, csu_dosuspenduserlist, "Lists suspended/locked users.", "Usage: suspenduserlist <username or pattern>\nDisplays all suspend users with usernames matching the specified pattern,\nor the single user with the specified username.\n");
  chanservaddcommand("unsuspenduser", QCMD_OPER, 1, csu_dounsuspenduser, "Unsuspend a user.", "Usage: unsuspenduser <username>\nUnsuspends the specified user.\n");
  chanservaddcommand("usercomment", QCMD_OPER, 2, csu_dousercomment, "Shows or changes staff comment for a user.", "Usage: usercomment <username> [<comment>]\nShows or changes the staff comment for the specified user.\n");
  chanservaddcommand("userflags", QCMD_AUTHED, 2, csu_douserflags, "Shows or changes user flags.", "Usage: USERFLAGS <flags>\nChanges your current user flags, where:\nflags - changes to apply, in the usual flag letters preceded by +/- format.\nValid user flags are:\n +n NOTICE  - causes the bot to sent you NOTICEs.  If this flag is not set the\n              bot will communicate using PRIVMSG.\n");
  chanservaddcommand("whoami", QCMD_AUTHED, 0, csu_dowhoami, "Displays information about you", "Usage: WHOAMI\nDisplays various information about your account.\n");
  chanservaddcommand("whois", QCMD_AUTHED, 1, csu_dowhois, "Displays information about a user.", "Usage: WHOIS <user>\nDisplays information about a user, where:\nuser  - user to request information for, either the nickname of an active user on\n        the network or #accountname.\n");
}

void _fini() {
  usercmds_fini();
  chanservremovecommand("accounthistory", csa_doaccounthistory);
  chanservremovecommand("cleanupdb", csu_docleanupdb);
  chanservremovecommand("deluser", csu_dodeluser);
  chanservremovecommand("domainmode", csu_dodomainmode);
  chanservremovecommand("info", csu_doinfo);
  chanservremovecommand("language", csu_dolanguage);
  chanservremovecommand("listflags", csu_dolistflags);
  chanservremovecommand("maillock", csu_domaillock);
  chanservremovecommand("rollbackaccount", csa_dorollbackaccount);
  chanservremovecommand("spewdb", csu_dospewdb);
  chanservremovecommand("spewdomain", csu_dospewdomain);
  chanservremovecommand("spewemail", csu_dospewemail);
  chanservremovecommand("spewpass", csu_dospewpass);
  chanservremovecommand("suspenduser", csu_dosuspenduser);
  chanservremovecommand("suspenduserlist", csu_dosuspenduserlist);
  chanservremovecommand("unsuspenduser", csu_dounsuspenduser);
  chanservremovecommand("usercomment", csu_dousercomment);
  chanservremovecommand("userflags", csu_douserflags);
  chanservremovecommand("whoami", csu_dowhoami);
  chanservremovecommand("whois", csu_dowhois);
}
