typedef struct _D3DKMT_QUERYCLOCKCALIBRATION {
  [in]  D3DKMT_HANDLE     hAdapter;
  [in]  UINT32            NodeOrdinal;
  [in]  UINT32            PhysicalAdapterIndex;
  [out] DXGK_GPUCLOCKDATA ClockData;
} D3DKMT_QUERYCLOCKCALIBRATION;