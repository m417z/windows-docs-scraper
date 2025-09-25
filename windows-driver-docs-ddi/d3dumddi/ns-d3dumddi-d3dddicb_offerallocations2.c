typedef struct D3DDDICB_OFFERALLOCATIONS2 {
       const HANDLE          *pResources;
  [in] const D3DKMT_HANDLE   *HandleList;
  [in] UINT                  NumAllocations;
       D3DDDI_OFFER_PRIORITY Priority;
       D3DDDI_OFFER_FLAGS    Flags;
} D3DDDICB_OFFERALLOCATIONS2;