typedef struct D3D12_VIDEO_ENCODER_HEAP_DESC {
  UINT                                              NodeMask;
  D3D12_VIDEO_ENCODER_HEAP_FLAGS                    Flags;
  D3D12_VIDEO_ENCODER_CODEC                         EncodeCodec;
  D3D12_VIDEO_ENCODER_PROFILE_DESC                  EncodeProfile;
  D3D12_VIDEO_ENCODER_LEVEL_SETTING                 EncodeLevel;
  UINT                                              ResolutionsListCount;
  const D3D12_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC *pResolutionList;
} D3D12_VIDEO_ENCODER_HEAP_DESC;