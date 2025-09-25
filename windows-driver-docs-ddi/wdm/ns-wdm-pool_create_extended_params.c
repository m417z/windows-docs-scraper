typedef struct _POOL_CREATE_EXTENDED_PARAMS {
  ULONG                           Version;
  ULONG                           ParameterCount;
  PPOOL_CREATE_EXTENDED_PARAMETER Parameters;
} POOL_CREATE_EXTENDED_PARAMS, *PPOOL_CREATE_EXTENDED_PARAMS;