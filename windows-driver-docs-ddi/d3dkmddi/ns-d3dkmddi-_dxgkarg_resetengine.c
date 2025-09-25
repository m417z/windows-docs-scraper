typedef struct _DXGKARG_RESETENGINE {
  [in]  UINT NodeOrdinal;
  [in]  UINT EngineOrdinal;
  [out] UINT LastAbortedFenceId;
} DXGKARG_RESETENGINE;