/* Automatically generated by mkcommandlist.pl, do not edit. */

#include "../chanserv.h"

/* Prototypes */
int csa_doauth(void *source, int cargc, char **cargv);
int csa_doauthhistory(void *source, int cargc, char **cargv);
int csa_doemail(void *source, int cargc, char **cargv);
int csa_dohello(void *source, int cargc, char **cargv);
int csa_doauth(void *source, int cargc, char **cargv);
int csa_donewpw(void *source, int cargc, char **cargv);
int csa_doreqmasterpw(void *source, int cargc, char **cargv);
int csa_doreqpw(void *source, int cargc, char **cargv);
int csa_dosetmail(void *source, int cargc, char **cargv);
int csa_dosetmasterpw(void *source, int cargc, char **cargv);
int csa_dosetpw(void *source, int cargc, char **cargv);

void _init() {
  chanservaddcommand("auth", QCMD_ALIAS | QCMD_SECURE | QCMD_NOTAUTHED, 2, csa_doauth, "Authenticates you on the bot.");
  chanservaddcommand("authhistory", QCMD_AUTHED, 1, csa_doauthhistory, "View auth history for an account.");
  chanservaddcommand("email", QCMD_AUTHED, 3, csa_doemail, "Change your email address.");
  chanservaddcommand("hello", QCMD_NOTAUTHED, 2, csa_dohello, "Creates a new user account.");
  chanservaddcommand("login", QCMD_SECURE | QCMD_NOTAUTHED, 2, csa_doauth, "Authenticates you on the bot.");
  chanservaddcommand("newpass", QCMD_AUTHED, 3, csa_donewpw, "Change your password.");
  chanservaddcommand("requestmasterpassword", QCMD_AUTHED, 1, csa_doreqmasterpw, "Requests a new master password by email.");
  chanservaddcommand("requestpassword", QCMD_NOTAUTHED, 2, csa_doreqpw, "Requests the current password by email.");
  chanservaddcommand("setemail", QCMD_OPER, 2, csa_dosetmail, "Set the email address.");
  chanservaddcommand("setmasterpassword", QCMD_OPER, 2, csa_dosetmasterpw, "Set the master password.");
  chanservaddcommand("setpassword", QCMD_OPER, 2, csa_dosetpw, "Set a new password.");
}

void _fini() {
  chanservremovecommand("auth", csa_doauth);
  chanservremovecommand("authhistory", csa_doauthhistory);
  chanservremovecommand("email", csa_doemail);
  chanservremovecommand("hello", csa_dohello);
  chanservremovecommand("login", csa_doauth);
  chanservremovecommand("newpass", csa_donewpw);
  chanservremovecommand("requestmasterpassword", csa_doreqmasterpw);
  chanservremovecommand("requestpassword", csa_doreqpw);
  chanservremovecommand("setemail", csa_dosetmail);
  chanservremovecommand("setmasterpassword", csa_dosetmasterpw);
  chanservremovecommand("setpassword", csa_dosetpw);
}
