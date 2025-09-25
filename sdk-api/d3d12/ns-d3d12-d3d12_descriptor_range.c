typedef struct D3D12_DESCRIPTOR_RANGE {
  D3D12_DESCRIPTOR_RANGE_TYPE RangeType;
  UINT                        NumDescriptors;
  UINT                        BaseShaderRegister;
  UINT                        RegisterSpace;
  UINT                        OffsetInDescriptorsFromTableStart;
} D3D12_DESCRIPTOR_RANGE;