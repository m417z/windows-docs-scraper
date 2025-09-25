typedef struct D3D12DDI_VIDEO_DECODE_HISTOGRAM_DATA_0041 {
  UINT                                                 NodeIndex;
  GUID                                                 DecodeProfile;
  UINT                                                 Width;
  UINT                                                 Height;
  DXGI_FORMAT                                          DecodeFormat;
  D3D12DDI_VIDEO_DECODE_HISTOGRAM_COMPONENT_FLAGS_0041 Components;
  UINT                                                 BinCount;
  UINT                                                 CounterBitDepth;
} D3D12DDI_VIDEO_DECODE_HISTOGRAM_DATA_0041;