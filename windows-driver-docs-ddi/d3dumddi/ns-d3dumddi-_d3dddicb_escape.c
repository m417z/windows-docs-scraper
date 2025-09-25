typedef struct _D3DDDICB_ESCAPE {
  [in]     HANDLE             hDevice;
  [in]     D3DDDI_ESCAPEFLAGS Flags;
  [in/out] VOID               *pPrivateDriverData;
  [in]     UINT               PrivateDriverDataSize;
  [in]     HANDLE             hContext;
} D3DDDICB_ESCAPE;