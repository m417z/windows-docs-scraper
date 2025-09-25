typedef struct D3D12_DESCRIPTOR_RANGE1 {
  D3D12_DESCRIPTOR_RANGE_TYPE  RangeType;
  UINT                         NumDescriptors;
  UINT                         BaseShaderRegister;
  UINT                         RegisterSpace;
  D3D12_DESCRIPTOR_RANGE_FLAGS Flags;
  UINT                         OffsetInDescriptorsFromTableStart;
} D3D12_DESCRIPTOR_RANGE1;