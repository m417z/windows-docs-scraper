typedef struct _DSOP_INIT_INFO {
  ULONG                 cbSize;
  PCWSTR                pwzTargetComputer;
  ULONG                 cDsScopeInfos;
  PDSOP_SCOPE_INIT_INFO aDsScopeInfos;
  ULONG                 flOptions;
  ULONG                 cAttributesToFetch;
  PCWSTR                *apwzAttributeNames;
} DSOP_INIT_INFO, *PDSOP_INIT_INFO;