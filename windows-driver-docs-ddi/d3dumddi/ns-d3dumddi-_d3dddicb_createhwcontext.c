typedef struct _D3DDDICB_CREATEHWCONTEXT {
  UINT                        NodeOrdinal;
  UINT                        EngineAffinity;
  D3DDDI_CREATEHWCONTEXTFLAGS Flags;
  UINT                        PrivateDriverDataSize;
  VOID                        *pPrivateDriverData;
  HANDLE                      hHwContext;
} D3DDDICB_CREATEHWCONTEXT;