typedef struct D3D12_VIDEO_DECODE_FRAME_ARGUMENT {
  D3D12_VIDEO_DECODE_ARGUMENT_TYPE Type;
  UINT                             Size;
  void                             *pData;
} D3D12_VIDEO_DECODE_FRAME_ARGUMENT;