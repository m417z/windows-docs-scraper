typedef struct D3D12_FEATURE_DATA_VIDEO_PROCESSOR_SIZE {
  UINT                                         NodeMask;
  const D3D12_VIDEO_PROCESS_OUTPUT_STREAM_DESC *pOutputStreamDesc;
  UINT                                         NumInputStreamDescs;
  const D3D12_VIDEO_PROCESS_INPUT_STREAM_DESC  *pInputStreamDescs;
  UINT64                                       MemoryPoolL0Size;
  UINT64                                       MemoryPoolL1Size;
} D3D12_FEATURE_DATA_VIDEO_PROCESSOR_SIZE;