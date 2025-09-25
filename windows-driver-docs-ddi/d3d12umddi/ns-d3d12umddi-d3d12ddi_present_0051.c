typedef struct D3D12DDI_PRESENT_0051 {
  D3DKMT_HANDLE               BroadcastSrcAllocation[D3DDDI_MAX_BROADCAST_CONTEXT + 1];
  D3DKMT_HANDLE               BroadcastDstAllocation[D3DDDI_MAX_BROADCAST_CONTEXT + 1];
  BOOL                        AddedGpuWork;
  UINT                        BackBufferMultiplicity;
  BOOL                        SyncIntervalOverrideValid;
  DXGI_DDI_FLIP_INTERVAL_TYPE SyncIntervalOverride;
} D3D12DDI_PRESENT_0051;