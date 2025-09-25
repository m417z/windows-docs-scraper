typedef struct _DXGKARGCB_MAPCONTEXTALLOCATION {
  [in] D3DGPU_VIRTUAL_ADDRESS                  BaseAddress;
  [in] D3DGPU_VIRTUAL_ADDRESS                  MinimumAddress;
  [in] D3DGPU_VIRTUAL_ADDRESS                  MaximumAddress;
  [in] HANDLE                                  hAllocation;
  [in] D3DGPU_SIZE_T                           OffsetInPages;
  [in] D3DGPU_SIZE_T                           SizeInPages;
  [in] D3DDDIGPUVIRTUALADDRESS_PROTECTION_TYPE Protection;
  [in] UINT64                                  DriverProtection;
} DXGKARGCB_MAPCONTEXTALLOCATION;