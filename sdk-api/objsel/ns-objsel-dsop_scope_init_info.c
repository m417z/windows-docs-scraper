typedef struct _DSOP_SCOPE_INIT_INFO {
  ULONG             cbSize;
  ULONG             flType;
  ULONG             flScope;
  DSOP_FILTER_FLAGS FilterFlags;
  PCWSTR            pwzDcName;
  PCWSTR            pwzADsPath;
  HRESULT           hr;
} DSOP_SCOPE_INIT_INFO, *PDSOP_SCOPE_INIT_INFO;