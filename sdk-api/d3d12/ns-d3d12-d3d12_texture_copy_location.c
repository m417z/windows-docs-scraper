typedef struct D3D12_TEXTURE_COPY_LOCATION {
  ID3D12Resource          *pResource;
  D3D12_TEXTURE_COPY_TYPE Type;
  union {
    D3D12_PLACED_SUBRESOURCE_FOOTPRINT PlacedFootprint;
    UINT                               SubresourceIndex;
  };
} D3D12_TEXTURE_COPY_LOCATION;