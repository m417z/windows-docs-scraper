typedef struct _D3DDDI_GETRESOURCEPRESENTPRIVATEDRIVERDATA {
  [in]      D3DKMT_HANDLE hResource;
  [in, out] UINT          PrivateDriverDataSize;
  [in, out] PVOID         pPrivateDriverData;
} D3DDDI_GETRESOURCEPRESENTPRIVATEDRIVERDATA;