typedef struct D3D12_HEAP_DESC {
  UINT64                SizeInBytes;
  D3D12_HEAP_PROPERTIES Properties;
  UINT64                Alignment;
  D3D12_HEAP_FLAGS      Flags;
} D3D12_HEAP_DESC;