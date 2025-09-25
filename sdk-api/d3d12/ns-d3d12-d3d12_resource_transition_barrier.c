typedef struct D3D12_RESOURCE_TRANSITION_BARRIER {
  ID3D12Resource        *pResource;
  UINT                  Subresource;
  D3D12_RESOURCE_STATES StateBefore;
  D3D12_RESOURCE_STATES StateAfter;
} D3D12_RESOURCE_TRANSITION_BARRIER;