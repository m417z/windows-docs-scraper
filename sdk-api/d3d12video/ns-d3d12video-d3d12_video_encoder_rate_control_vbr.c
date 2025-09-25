typedef struct D3D12_VIDEO_ENCODER_RATE_CONTROL_VBR {
  UINT   InitialQP;
  UINT   MinQP;
  UINT   MaxQP;
  UINT64 MaxFrameBitSize;
  UINT64 TargetAvgBitRate;
  UINT64 PeakBitRate;
  UINT64 VBVCapacity;
  UINT64 InitialVBVFullness;
} D3D12_VIDEO_ENCODER_RATE_CONTROL_VBR;