typedef struct _D3DDDIARG_RECLAIMRESOURCES {
  [in]  HANDLE *pResources;
  [out] BOOL   *pDiscarded;
  [in]  UINT   Resources;
} D3DDDIARG_RECLAIMRESOURCES;