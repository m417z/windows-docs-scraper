typedef struct D3D11_FEATURE_DATA_VIDEO_DECODER_HISTOGRAM {
  D3D11_VIDEO_DECODER_DESC                      DecoderDesc;
  D3D11_VIDEO_DECODER_HISTOGRAM_COMPONENT_FLAGS Components;
  UINT                                          BinCount;
  UINT                                          CounterBitDepth;
} D3D11_FEATURE_DATA_VIDEO_DECODER_HISTOGRAM;