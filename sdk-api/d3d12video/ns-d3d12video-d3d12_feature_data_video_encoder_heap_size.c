typedef struct D3D12_FEATURE_DATA_VIDEO_ENCODER_HEAP_SIZE {
  D3D12_VIDEO_ENCODER_HEAP_DESC HeapDesc;
  BOOL                          IsSupported;
  UINT64                        MemoryPoolL0Size;
  UINT64                        MemoryPoolL1Size;
} D3D12_FEATURE_DATA_VIDEO_ENCODER_HEAP_SIZE;