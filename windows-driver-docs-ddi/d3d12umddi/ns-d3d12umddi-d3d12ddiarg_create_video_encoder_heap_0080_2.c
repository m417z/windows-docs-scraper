typedef struct D3D12DDIARG_CREATE_VIDEO_ENCODER_HEAP_0080_2 {
  UINT                                                      NodeMask;
  D3D12DDI_VIDEO_ENCODER_HEAP_FLAGS_0080                    Flags;
  D3D12DDI_VIDEO_ENCODER_CODEC_0080                         EncodeCodec;
  D3D12DDI_VIDEO_ENCODER_PROFILE_DESC_0080_2                EncodeProfile;
  D3D12DDI_VIDEO_ENCODER_LEVEL_SETTING_0080_2               EncodeLevel;
  UINT                                                      ResolutionsListCount;
  const D3D12DDI_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC_0080 *pResolutionList;
} D3D12DDIARG_CREATE_VIDEO_ENCODER_HEAP_0080_2;