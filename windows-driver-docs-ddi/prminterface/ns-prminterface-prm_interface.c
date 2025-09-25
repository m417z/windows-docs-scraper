typedef struct _PRM_INTERFACE {
  ULONG               Version;
  PPRM_UNLOCK_MODULE  UnlockModule;
  PPRM_LOCK_MODULE    LockModule;
  PPRM_INVOKE_HANDLER InvokeHandler;
  PPRM_QUERY_HANDLER  QueryHandler;
} PRM_INTERFACE, *PPRM_INTERFACE;