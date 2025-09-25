typedef struct DXGIDDICB_PRESENT_MULTIPLANE_OVERLAY {
  [in] void                                       *pDXGIContext;
  [in] HANDLE                                     hContext;
  [in] UINT                                       BroadcastContextCount;
       HANDLE                                     BroadcastContext[D3DDDI_MAX_BROADCAST_CONTEXT];
  [in] DWORD                                      AllocationInfoCount;
       DXGIDDI_MULTIPLANE_OVERLAY_ALLOCATION_INFO AllocationInfo[DXGI_DDI_MAX_MULTIPLANE_OVERLAY_ALLOCATIONS];
} DXGIDDICB_PRESENT_MULTIPLANE_OVERLAY;