typedef struct _DXGK_OPENALLOCATIONINFO {
  [in]     D3DKMT_HANDLE hAllocation;
  [in/out] VOID          *pPrivateDriverData;
  [in]     UINT          PrivateDriverDataSize;
  [out]    HANDLE        hDeviceSpecificAllocation;
} DXGK_OPENALLOCATIONINFO;