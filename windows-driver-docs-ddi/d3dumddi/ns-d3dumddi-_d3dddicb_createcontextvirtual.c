typedef struct _D3DDDICB_CREATECONTEXTVIRTUAL {
  [in]  UINT                      NodeOrdinal;
  [in]  UINT                      EngineAffinity;
  [in]  D3DDDI_CREATECONTEXTFLAGS Flags;
  [in]  VOID                      *pPrivateDriverData;
  [in]  UINT                      PrivateDriverDataSize;
  [out] HANDLE                    hContext;
} D3DDDICB_CREATECONTEXTVIRTUAL;