typedef struct _DXGKARG_ESCAPE {
  [in]     HANDLE             hDevice;
  [in]     D3DDDI_ESCAPEFLAGS Flags;
  [in/out] VOID               *pPrivateDriverData;
  [in/out] UINT               PrivateDriverDataSize;
  [in]     HANDLE             hContext;
  [in]     HANDLE             hKmdProcessHandle;
} DXGKARG_ESCAPE;