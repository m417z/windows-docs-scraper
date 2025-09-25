typedef struct D3D12_BUFFER_SRV {
  UINT64                 FirstElement;
  UINT                   NumElements;
  UINT                   StructureByteStride;
  D3D12_BUFFER_SRV_FLAGS Flags;
} D3D12_BUFFER_SRV;