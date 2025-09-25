typedef struct _D3DDDI_KERNELOVERLAYINFO {
  [in] D3DKMT_HANDLE hAllocation;
  [in] D3DDDIRECT    DstRect;
  [in] D3DDDIRECT    SrcRect;
  [in] VOID          *pPrivateDriverData;
  [in] UINT          PrivateDriverDataSize;
} D3DDDI_KERNELOVERLAYINFO;