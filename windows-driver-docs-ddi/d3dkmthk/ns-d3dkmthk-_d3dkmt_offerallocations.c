typedef struct _D3DKMT_OFFERALLOCATIONS {
  [in] D3DKMT_HANDLE         hDevice;
  [in] D3DKMT_HANDLE         *pResources;
  [in] const D3DKMT_HANDLE   *HandleList;
  [in] UINT                  NumAllocations;
  [in] D3DKMT_OFFER_PRIORITY Priority;
       D3DKMT_OFFER_FLAGS    Flags;
} D3DKMT_OFFERALLOCATIONS;