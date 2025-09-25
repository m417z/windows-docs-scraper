typedef struct _D3D11_1DDI_GETCAPTUREHANDLEDATA {
  [in]  D3D10DDI_HRESOURCE hResource;
  [in]  UINT               ArrayIndex;
  [out] D3DKMT_HANDLE      hAllocation;
  [out] UINT               DataOffset;
  [out] UINT               DataSize;
} D3D11_1DDI_GETCAPTUREHANDLEDATA;