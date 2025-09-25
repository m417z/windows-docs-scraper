HRESULT CreateVideoDecoderHeap1(
  const D3D12_VIDEO_DECODER_HEAP_DESC *pVideoDecoderHeapDesc,
  ID3D12ProtectedResourceSession      *pProtectedResourceSession,
  REFIID                              riid,
  void                                **ppVideoDecoderHeap
);