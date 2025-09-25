typedef struct D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_0080_2 {
  D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_FLAGS_0080        ConfigurationFlags;
  D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_DIRECT_MODES_0080 DirectModeConfig;
  UCHAR                                                             pic_order_cnt_type;
  UCHAR                                                             log2_max_frame_num_minus4;
  UCHAR                                                             log2_max_pic_order_cnt_lsb_minus4;
} D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_0080_2;