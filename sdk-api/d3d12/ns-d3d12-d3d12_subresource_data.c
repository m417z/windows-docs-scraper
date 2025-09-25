typedef struct D3D12_SUBRESOURCE_DATA {
  const void *pData;
  LONG_PTR   RowPitch;
  LONG_PTR   SlicePitch;
} D3D12_SUBRESOURCE_DATA;