typedef struct _D3DDDICB_OFFERALLOCATIONS {
  [in] const HANDLE          *pResources;
  [in] const D3DKMT_HANDLE   *HandleList;
  [in] UINT                  NumAllocations;
  [in] D3DDDI_OFFER_PRIORITY Priority;
} D3DDDICB_OFFERALLOCATIONS;