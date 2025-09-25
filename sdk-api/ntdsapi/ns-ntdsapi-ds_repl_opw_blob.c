typedef struct _DS_REPL_OPW_BLOB {
  FILETIME        ftimeEnqueued;
  ULONG           ulSerialNumber;
  ULONG           ulPriority;
  DS_REPL_OP_TYPE OpType;
  ULONG           ulOptions;
  DWORD           oszNamingContext;
  DWORD           oszDsaDN;
  DWORD           oszDsaAddress;
  UUID            uuidNamingContextObjGuid;
  UUID            uuidDsaObjGuid;
} DS_REPL_OPW_BLOB;