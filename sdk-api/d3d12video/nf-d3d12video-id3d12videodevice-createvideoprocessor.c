HRESULT CreateVideoProcessor(
  UINT                                         NodeMask,
  const D3D12_VIDEO_PROCESS_OUTPUT_STREAM_DESC *pOutputStreamDesc,
  UINT                                         NumInputStreamDescs,
  const D3D12_VIDEO_PROCESS_INPUT_STREAM_DESC  *pInputStreamDescs,
  REFIID                                       riid,
  void                                         **ppVideoProcessor
);