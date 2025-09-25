typedef struct D3D12_FEATURE_DATA_VIDEO_DECODER_HEAP_SIZE {
  D3D12_VIDEO_DECODER_HEAP_DESC VideoDecoderHeapDesc;
  UINT64                        MemoryPoolL0Size;
  UINT64                        MemoryPoolL1Size;
} D3D12_FEATURE_DATA_VIDEO_DECODER_HEAP_SIZE;