typedef struct D3D12_FEATURE_DATA_VIDEO_ENCODER_RATE_CONTROL_FRAME_ANALYSIS {
  UINT                                                          NodeIndex;
  D3D12_VIDEO_ENCODER_CODEC                                     Codec;
  D3D12_VIDEO_ENCODER_PROFILE_DESC                              Profile;
  D3D12_VIDEO_ENCODER_LEVEL_SETTING                             Level;
  DXGI_FORMAT                                                   InputFormat;
  D3D12_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC                   InputResolution;
  D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION                       CodecConfiguration;
  D3D12_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE               SubregionFrameEncoding;
  D3D12_VIDEO_ENCODER_PICTURE_CONTROL_SUBREGIONS_LAYOUT_DATA    SubregionFrameEncodingData;
  D3D12_VIDEO_ENCODER_QPMAP_CONFIGURATION                       QPMap;
  D3D12_VIDEO_ENCODER_DIRTY_REGIONS_CONFIGURATION               DirtyRegions;
  D3D12_VIDEO_ENCODER_MOTION_SEARCH_CONFIGURATION               MotionSearch;
  UINT                                                          Pow2DownscaleFactor;
  D3D12_VIDEO_ENCODER_RATE_CONTROL_FRAME_ANALYSIS_SUPPORT_FLAGS SupportFlags;
} D3D12_FEATURE_DATA_VIDEO_ENCODER_RATE_CONTROL_FRAME_ANALYSIS;