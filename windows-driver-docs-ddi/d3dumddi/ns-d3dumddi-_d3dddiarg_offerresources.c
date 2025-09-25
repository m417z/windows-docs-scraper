typedef struct _D3DDDIARG_OFFERRESOURCES {
  [in] const HANDLE          *pResources;
  [in] UINT                  Resources;
  [in] D3DDDI_OFFER_PRIORITY Priority;
} D3DDDIARG_OFFERRESOURCES;