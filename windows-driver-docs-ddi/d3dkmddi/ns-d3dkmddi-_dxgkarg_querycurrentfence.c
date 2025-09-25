typedef struct _DXGKARG_QUERYCURRENTFENCE {
  [out] UINT CurrentFence;
  [in]  UINT NodeOrdinal;
  [in]  UINT EngineOrdinal;
} DXGKARG_QUERYCURRENTFENCE;