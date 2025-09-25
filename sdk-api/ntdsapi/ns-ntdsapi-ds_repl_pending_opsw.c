typedef struct _DS_REPL_PENDING_OPSW {
  FILETIME    ftimeCurrentOpStarted;
  DWORD       cNumPendingOps;
#if ...
  DS_REPL_OPW rgPendingOp[];
#else
  DS_REPL_OPW rgPendingOp[1];
#endif
} DS_REPL_PENDING_OPSW;