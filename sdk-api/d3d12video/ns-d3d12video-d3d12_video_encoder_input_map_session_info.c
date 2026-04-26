typedef struct D3D12_VIDEO_ENCODER_INPUT_MAP_SESSION_INFO {
  D3D12_VIDEO_ENCODER_CODEC                                  Codec;
  D3D12_VIDEO_ENCODER_PROFILE_DESC                           Profile;
  D3D12_VIDEO_ENCODER_LEVEL_SETTING                          Level;
  DXGI_FORMAT                                                InputFormat;
  D3D12_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC                InputResolution;
  D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION                    CodecConfiguration;
  D3D12_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE            SubregionFrameEncoding;
  D3D12_VIDEO_ENCODER_PICTURE_CONTROL_SUBREGIONS_LAYOUT_DATA SubregionFrameEncodingData;
} D3D12_VIDEO_ENCODER_INPUT_MAP_SESSION_INFO;