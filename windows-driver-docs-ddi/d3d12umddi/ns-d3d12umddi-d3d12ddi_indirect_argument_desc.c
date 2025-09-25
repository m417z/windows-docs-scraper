typedef struct D3D12DDI_INDIRECT_ARGUMENT_DESC {
  D3D12DDI_INDIRECT_ARGUMENT_TYPE Type;
  union {
    struct {
      UINT Slot;
    } VertexBuffer;
    struct {
      UINT RootParameterIndex;
      UINT DestOffsetIn32BitValues;
      UINT Num32BitValuesToSet;
    } Constant;
    struct {
      UINT RootParameterIndex;
    } ConstantBufferView;
    struct {
      UINT RootParameterIndex;
    } ShaderResourceView;
    struct {
      UINT RootParameterIndex;
    } UnorderedAccessView;
    struct {
      UINT RootParameterIndex;
      UINT DestOffsetIn32BitValues;
    } IncrementingConstant;
  };
} D3D12DDI_INDIRECT_ARGUMENT_DESC;