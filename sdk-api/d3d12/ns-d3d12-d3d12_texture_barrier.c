typedef struct D3D12_TEXTURE_BARRIER {
  D3D12_BARRIER_SYNC              SyncBefore;
  D3D12_BARRIER_SYNC              SyncAfter;
  D3D12_BARRIER_ACCESS            AccessBefore;
  D3D12_BARRIER_ACCESS            AccessAfter;
  D3D12_BARRIER_LAYOUT            LayoutBefore;
  D3D12_BARRIER_LAYOUT            LayoutAfter;
  ID3D12Resource                  *pResource;
  D3D12_BARRIER_SUBRESOURCE_RANGE Subresources;
  D3D12_TEXTURE_BARRIER_FLAGS     Flags;
} D3D12_TEXTURE_BARRIER;