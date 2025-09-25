typedef struct D3D12_VIDEO_DECODE_OUTPUT_STREAM_ARGUMENTS {
  ID3D12Resource                          *pOutputTexture2D;
  UINT                                    OutputSubresource;
  D3D12_VIDEO_DECODE_CONVERSION_ARGUMENTS ConversionArguments;
} D3D12_VIDEO_DECODE_OUTPUT_STREAM_ARGUMENTS;