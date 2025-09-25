typedef struct _DS_REPL_OPW {
  FILETIME        ftimeEnqueued;
  ULONG           ulSerialNumber;
  ULONG           ulPriority;
  DS_REPL_OP_TYPE OpType;
  ULONG           ulOptions;
  LPWSTR          pszNamingContext;
  LPWSTR          pszDsaDN;
  LPWSTR          pszDsaAddress;
  UUID            uuidNamingContextObjGuid;
  UUID            uuidDsaObjGuid;
} DS_REPL_OPW;