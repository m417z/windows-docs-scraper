typedef struct D3D12_VIDEO_ENCODER_SEQUENCE_GOP_STRUCTURE_H264 {
  UINT  GOPLength;
  UINT  PPicturePeriod;
  UCHAR pic_order_cnt_type;
  UCHAR log2_max_frame_num_minus4;
  UCHAR log2_max_pic_order_cnt_lsb_minus4;
} D3D12_VIDEO_ENCODER_SEQUENCE_GOP_STRUCTURE_H264;