typedef struct D3D12DDI_VIDEO_PROCESSOR_SIZE_DATA_0072 {
  [in]  UINT                                            NodeMask;
  [in]  D3D12DDI_VIDEO_PROCESS_OUTPUT_STREAM_DESC_0032  OutputStream;
  [in]  D3D12DDI_VIDEO_PROCESSOR_INPUT_STREAM_DESC_0043 *pInputStreams;
  [in]  UINT                                            NumInputStreams;
  [in]  BOOL                                            Protected;
  [out] UINT64                                          MemoryPoolL0Size;
  [out] UINT64                                          MemoryPoolL1Size;
} D3D12DDI_VIDEO_PROCESSOR_SIZE_DATA_0072;