HRESULT CreateVideoMotionEstimator(
  const D3D12_VIDEO_MOTION_ESTIMATOR_DESC *pDesc,
  ID3D12ProtectedResourceSession          *pProtectedResourceSession,
  REFIID                                  riid,
  void                                    **ppVideoMotionEstimator
);