typedef struct _D3DDDICB_QUERYADAPTERINFO2 {
  [in]     D3DDDI_QUERYADAPTERTYPE QueryType;
  [out]    VOID                    *pPrivateDriverData;
  [in/out] UINT                    PrivateDriverDataSize;
} D3DDDICB_QUERYADAPTERINFO2;