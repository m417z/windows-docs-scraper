typedef struct _D3DKMT_CREATEHWCONTEXT {
  D3DKMT_HANDLE               hDevice;
  UINT                        NodeOrdinal;
  UINT                        EngineAffinity;
  D3DDDI_CREATEHWCONTEXTFLAGS Flags;
  UINT                        PrivateDriverDataSize;
  VOID                        *pPrivateDriverData;
  D3DKMT_HANDLE               hHwContext;
} D3DKMT_CREATEHWCONTEXT;