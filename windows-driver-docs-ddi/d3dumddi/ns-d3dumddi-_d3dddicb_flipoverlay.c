typedef struct _D3DDDICB_FLIPOVERLAY {
  [in] D3DKMT_HANDLE hKernelOverlay;
  [in] D3DKMT_HANDLE hSource;
  [in] VOID          *pPrivateDriverData;
  [in] UINT          PrivateDriverDataSize;
} D3DDDICB_FLIPOVERLAY;