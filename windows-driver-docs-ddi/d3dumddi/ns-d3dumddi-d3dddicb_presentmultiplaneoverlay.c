typedef struct D3DDDICB_PRESENTMULTIPLANEOVERLAY {
  [in] HANDLE                            hContext;
  [in] UINT                              BroadcastContextCount;
       HANDLE                            BroadcastContext[D3DDDI_MAX_BROADCAST_CONTEXT];
  [in] UINT                              AllocationInfoCount;
       D3DDDI_MULTIPLANE_ALLOCATION_INFO AllocationInfo[D3DDDI_MAX_MULTIPLANE_OVERLAY_ALLOCATIONS];
} D3DDDICB_PRESENTMULTIPLANEOVERLAY;