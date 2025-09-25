typedef struct _DXGKARG_QUERYENGINESTATUS {
  [in]  UINT              NodeOrdinal;
  [in]  UINT              EngineOrdinal;
  [out] DXGK_ENGINESTATUS EngineStatus;
} DXGKARG_QUERYENGINESTATUS;