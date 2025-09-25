typedef struct D3D12_BUFFER_UAV {
  UINT64                 FirstElement;
  UINT                   NumElements;
  UINT                   StructureByteStride;
  UINT64                 CounterOffsetInBytes;
  D3D12_BUFFER_UAV_FLAGS Flags;
} D3D12_BUFFER_UAV;