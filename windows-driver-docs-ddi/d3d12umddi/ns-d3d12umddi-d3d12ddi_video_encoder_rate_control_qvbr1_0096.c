typedef struct D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_QVBR1_0096 {
  UINT   InitialQP;
  UINT   MinQP;
  UINT   MaxQP;
  UINT64 MaxFrameBitSize;
  UINT64 TargetAvgBitRate;
  UINT64 PeakBitRate;
  UINT   ConstantQualityTarget;
  UINT64 VBVCapacity;
  UINT64 InitialVBVFullness;
  UINT   QualityVsSpeed;
} D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_QVBR1_0096;