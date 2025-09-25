typedef struct _WDF_DPC_CONFIG {
  ULONG       Size;
  PFN_WDF_DPC EvtDpcFunc;
  BOOLEAN     AutomaticSerialization;
} WDF_DPC_CONFIG, *PWDF_DPC_CONFIG;