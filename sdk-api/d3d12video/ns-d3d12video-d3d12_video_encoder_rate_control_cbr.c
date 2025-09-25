typedef struct D3D12_VIDEO_ENCODER_RATE_CONTROL_CBR {
  UINT   InitialQP;
  UINT   MinQP;
  UINT   MaxQP;
  UINT64 MaxFrameBitSize;
  UINT64 TargetBitRate;
  UINT64 VBVCapacity;
  UINT64 InitialVBVFullness;
} D3D12_VIDEO_ENCODER_RATE_CONTROL_CBR;