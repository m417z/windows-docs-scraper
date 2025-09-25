typedef struct D3D12_RESOURCE_ALIASING_BARRIER {
  ID3D12Resource *pResourceBefore;
  ID3D12Resource *pResourceAfter;
} D3D12_RESOURCE_ALIASING_BARRIER;