typedef struct _D3DKMT_FLIPOVERLAY {
  [in] D3DKMT_HANDLE hDevice;
  [in] D3DKMT_HANDLE hOverlay;
  [in] D3DKMT_HANDLE hSource;
  [in] VOID          *pPrivateDriverData;
  [in] UINT          PrivateDriverDataSize;
} D3DKMT_FLIPOVERLAY;