typedef struct D3D12_BUFFER_BARRIER {
  D3D12_BARRIER_SYNC   SyncBefore;
  D3D12_BARRIER_SYNC   SyncAfter;
  D3D12_BARRIER_ACCESS AccessBefore;
  D3D12_BARRIER_ACCESS AccessAfter;
  ID3D12Resource       *pResource;
  UINT64               Offset;
  UINT64               Size;
} D3D12_BUFFER_BARRIER;