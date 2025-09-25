typedef struct _DXGKARG_CREATECONTEXT {
  [out] HANDLE                  hContext;
  [in]  UINT                    NodeOrdinal;
  [in]  UINT                    EngineAffinity;
  [in]  DXGK_CREATECONTEXTFLAGS Flags;
  [in]  VOID                    *pPrivateDriverData;
  [in]  UINT                    PrivateDriverDataSize;
  [out] DXGK_CONTEXTINFO        ContextInfo;
} DXGKARG_CREATECONTEXT;