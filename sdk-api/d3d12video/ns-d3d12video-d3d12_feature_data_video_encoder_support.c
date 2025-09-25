typedef struct D3D12_FEATURE_DATA_VIDEO_ENCODER_SUPPORT {
  UINT                                                       NodeIndex;
  D3D12_VIDEO_ENCODER_CODEC                                  Codec;
  DXGI_FORMAT                                                InputFormat;
  D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION                    CodecConfiguration;
  D3D12_VIDEO_ENCODER_SEQUENCE_GOP_STRUCTURE                 CodecGopSequence;
  D3D12_VIDEO_ENCODER_RATE_CONTROL                           RateControl;
  D3D12_VIDEO_ENCODER_INTRA_REFRESH_MODE                     IntraRefresh;
  D3D12_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE            SubregionFrameEncoding;
  UINT                                                       ResolutionsListCount;
  const D3D12_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC          *pResolutionList;
  UINT                                                       MaxReferenceFramesInDPB;
  D3D12_VIDEO_ENCODER_VALIDATION_FLAGS                       ValidationFlags;
  D3D12_VIDEO_ENCODER_SUPPORT_FLAGS                          SupportFlags;
  D3D12_VIDEO_ENCODER_PROFILE_DESC                           SuggestedProfile;
  D3D12_VIDEO_ENCODER_LEVEL_SETTING                          SuggestedLevel;
  D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOLUTION_SUPPORT_LIMITS *pResolutionDependentSupport;
} D3D12_FEATURE_DATA_VIDEO_ENCODER_SUPPORT;