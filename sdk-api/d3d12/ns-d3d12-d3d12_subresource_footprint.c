typedef struct D3D12_SUBRESOURCE_FOOTPRINT {
  DXGI_FORMAT Format;
  UINT        Width;
  UINT        Height;
  UINT        Depth;
  UINT        RowPitch;
} D3D12_SUBRESOURCE_FOOTPRINT;