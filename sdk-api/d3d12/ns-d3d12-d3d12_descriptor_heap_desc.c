typedef struct D3D12_DESCRIPTOR_HEAP_DESC {
  D3D12_DESCRIPTOR_HEAP_TYPE  Type;
  UINT                        NumDescriptors;
  D3D12_DESCRIPTOR_HEAP_FLAGS Flags;
  UINT                        NodeMask;
} D3D12_DESCRIPTOR_HEAP_DESC;