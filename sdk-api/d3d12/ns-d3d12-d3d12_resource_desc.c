typedef struct D3D12_RESOURCE_DESC {
  D3D12_RESOURCE_DIMENSION Dimension;
  UINT64                   Alignment;
  UINT64                   Width;
  UINT                     Height;
  UINT16                   DepthOrArraySize;
  UINT16                   MipLevels;
  DXGI_FORMAT              Format;
  DXGI_SAMPLE_DESC         SampleDesc;
  D3D12_TEXTURE_LAYOUT     Layout;
  D3D12_RESOURCE_FLAGS     Flags;
} D3D12_RESOURCE_DESC;