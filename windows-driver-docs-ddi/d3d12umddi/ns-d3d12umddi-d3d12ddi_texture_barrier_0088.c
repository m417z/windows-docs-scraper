typedef struct D3D12DDI_TEXTURE_BARRIER_0088 {
  D3D12DDI_BARRIER_SYNC                   SyncBefore;
  D3D12DDI_BARRIER_SYNC                   SyncAfter;
  D3D12DDI_BARRIER_ACCESS                 AccessBefore;
  D3D12DDI_BARRIER_ACCESS                 AccessAfter;
  D3D12DDI_BARRIER_LAYOUT                 LayoutBefore;
  D3D12DDI_BARRIER_LAYOUT                 LayoutAfter;
  D3D12DDI_HRESOURCE                      hResource;
  D3D12DDI_BARRIER_SUBRESOURCE_RANGE_0088 Subresources;
  D3D12DDI_TEXTURE_BARRIER_FLAGS_0088     Flags;
} D3D12DDI_TEXTURE_BARRIER_0088;