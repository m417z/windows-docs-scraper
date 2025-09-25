typedef struct D3D12_VIDEO_ENCODER_OUTPUT_METADATA {
  UINT64                                         EncodeErrorFlags;
  D3D12_VIDEO_ENCODER_OUTPUT_METADATA_STATISTICS EncodeStats;
  UINT64                                         EncodedBitstreamWrittenBytesCount;
  UINT64                                         WrittenSubregionsCount;
} D3D12_VIDEO_ENCODER_OUTPUT_METADATA;