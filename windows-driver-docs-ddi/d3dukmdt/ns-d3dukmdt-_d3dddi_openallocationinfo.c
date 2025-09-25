typedef struct _D3DDDI_OPENALLOCATIONINFO {
  [in] D3DKMT_HANDLE hAllocation;
  [in] const VOID    *pPrivateDriverData;
  [in] UINT          PrivateDriverDataSize;
} D3DDDI_OPENALLOCATIONINFO;