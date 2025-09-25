typedef struct D3D12_VIDEO_DECODE_OUTPUT_STREAM_ARGUMENTS1 {
  ID3D12Resource                           *pOutputTexture2D;
  UINT                                     OutputSubresource;
  D3D12_VIDEO_DECODE_CONVERSION_ARGUMENTS1 ConversionArguments;
  D3D12_VIDEO_DECODE_OUTPUT_HISTOGRAM      Histograms[4];
} D3D12_VIDEO_DECODE_OUTPUT_STREAM_ARGUMENTS1;