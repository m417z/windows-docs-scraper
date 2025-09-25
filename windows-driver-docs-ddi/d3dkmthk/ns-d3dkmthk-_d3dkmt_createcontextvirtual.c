typedef struct _D3DKMT_CREATECONTEXTVIRTUAL {
  D3DKMT_HANDLE             hDevice;
  UINT                      NodeOrdinal;
  UINT                      EngineAffinity;
  D3DDDI_CREATECONTEXTFLAGS Flags;
  VOID                      *pPrivateDriverData;
  UINT                      PrivateDriverDataSize;
  D3DKMT_CLIENTHINT         ClientHint;
  D3DKMT_HANDLE             hContext;
} D3DKMT_CREATECONTEXTVIRTUAL;