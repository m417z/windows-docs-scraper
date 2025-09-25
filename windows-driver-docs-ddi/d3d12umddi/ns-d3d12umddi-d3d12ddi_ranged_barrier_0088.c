typedef struct D3D12DDI_RANGED_BARRIER_0088 {
  D3D12DDI_BARRIER_SYNC                   SyncBefore;
  D3D12DDI_BARRIER_SYNC                   SyncAfter;
  D3D12DDI_BARRIER_ACCESS                 AccessBefore;
  D3D12DDI_BARRIER_ACCESS                 AccessAfter;
  D3D12DDI_RANGED_BARRIER_FLAGS           Flags;
  D3D12DDI_HRESOURCE                      hResource;
  D3D12DDI_BARRIER_SUBRESOURCE_RANGE_0088 Subresources;
  D3D12DDI_RANGE                          Range;
} D3D12DDI_RANGED_BARRIER_0088;