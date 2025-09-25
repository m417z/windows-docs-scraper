typedef struct D3D12_VIDEO_DECODE_CONFIGURATION {
  GUID                                   DecodeProfile;
  D3D12_BITSTREAM_ENCRYPTION_TYPE        BitstreamEncryption;
  D3D12_VIDEO_FRAME_CODED_INTERLACE_TYPE InterlaceType;
} D3D12_VIDEO_DECODE_CONFIGURATION;