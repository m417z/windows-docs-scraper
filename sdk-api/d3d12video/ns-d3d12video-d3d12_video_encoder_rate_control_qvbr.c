typedef struct D3D12_VIDEO_ENCODER_RATE_CONTROL_QVBR {
  UINT   InitialQP;
  UINT   MinQP;
  UINT   MaxQP;
  UINT64 MaxFrameBitSize;
  UINT64 TargetAvgBitRate;
  UINT64 PeakBitRate;
  UINT   ConstantQualityTarget;
} D3D12_VIDEO_ENCODER_RATE_CONTROL_QVBR;