typedef struct _D3DKMT_ESCAPE {
  [in]     D3DKMT_HANDLE      hAdapter;
  [in]     D3DKMT_HANDLE      hDevice;
  [in]     D3DKMT_ESCAPETYPE  Type;
  [in]     D3DDDI_ESCAPEFLAGS Flags;
  [in/out] VOID               *pPrivateDriverData;
  [in]     UINT               PrivateDriverDataSize;
  [in]     D3DKMT_HANDLE      hContext;
} D3DKMT_ESCAPE;