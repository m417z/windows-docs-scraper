typedef struct D3D12DDIARG_CREATE_VIDEO_PROCESSOR_0032 {
  UINT                                            NodeMask;
  D3D12DDI_VIDEO_PROCESS_OUTPUT_STREAM_DESC_0032  OutputStream;
  D3D12DDI_VIDEO_PROCESSOR_INPUT_STREAM_DESC_0032 *pInputStreams;
  UINT                                            NumInputStreams;
} D3D12DDIARG_CREATE_VIDEO_PROCESSOR_0032;