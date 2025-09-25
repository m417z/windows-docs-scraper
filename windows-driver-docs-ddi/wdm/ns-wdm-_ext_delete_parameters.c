typedef struct _EXT_DELETE_PARAMETERS {
  ULONG                Version;
  ULONG                Reserved;
  PEXT_DELETE_CALLBACK DeleteCallback;
  PVOID                DeleteContext;
} EXT_DELETE_PARAMETERS, *PEXT_DELETE_PARAMETERS;