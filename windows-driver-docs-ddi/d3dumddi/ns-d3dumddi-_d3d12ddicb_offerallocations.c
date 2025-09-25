typedef struct _D3D12DDICB_OFFERALLOCATIONS {
  [in] UINT                  NumAllocations;
  [in] const D3DKMT_HANDLE   *HandleList;
       D3DDDI_OFFER_PRIORITY Priority;
} D3D12DDICB_OFFERALLOCATIONS;