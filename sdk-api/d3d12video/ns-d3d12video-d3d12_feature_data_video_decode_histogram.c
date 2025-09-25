typedef struct D3D12_FEATURE_DATA_VIDEO_DECODE_HISTOGRAM {
  UINT                                         NodeIndex;
  GUID                                         DecodeProfile;
  UINT                                         Width;
  UINT                                         Height;
  DXGI_FORMAT                                  DecodeFormat;
  D3D12_VIDEO_DECODE_HISTOGRAM_COMPONENT_FLAGS Components;
  UINT                                         BinCount;
  UINT                                         CounterBitDepth;
} D3D12_FEATURE_DATA_VIDEO_DECODE_HISTOGRAM;