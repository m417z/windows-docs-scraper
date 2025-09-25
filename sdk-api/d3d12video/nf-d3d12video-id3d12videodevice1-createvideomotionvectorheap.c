HRESULT CreateVideoMotionVectorHeap(
  const D3D12_VIDEO_MOTION_VECTOR_HEAP_DESC *pDesc,
  ID3D12ProtectedResourceSession            *pProtectedResourceSession,
  REFIID                                    riid,
  void                                      **ppVideoMotionVectorHeap
);