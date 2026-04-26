typedef struct D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOLUTION_SUPPORT_MOTION_SEARCH {
  UINT                                                                MaxMotionHints;
  UINT                                                                MinDeviation;
  UINT                                                                MaxDeviation;
  UINT                                                                MapSourcePreferenceRanking;
  D3D12_VIDEO_ENCODER_FRAME_INPUT_MOTION_UNIT_PRECISION_SUPPORT_FLAGS MotionUnitPrecisionSupportFlags;
  D3D12_VIDEO_ENCODER_MOTION_SEARCH_SUPPORT_FLAGS                     SupportFlags;
} D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOLUTION_SUPPORT_MOTION_SEARCH;