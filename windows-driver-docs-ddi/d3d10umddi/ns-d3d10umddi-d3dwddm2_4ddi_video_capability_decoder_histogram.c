typedef struct D3DWDDM2_4DDI_VIDEO_CAPABILITY_DECODER_HISTOGRAM {
  D3D11_1DDI_VIDEO_DECODER_DESC                         DecoderDesc;
  D3DWDDM2_4DDI_VIDEO_DECODER_HISTOGRAM_COMPONENT_FLAGS Components;
  UINT                                                  BinCount;
  UINT                                                  CounterBitDepth;
} D3DWDDM2_4DDI_VIDEO_CAPABILITY_DECODER_HISTOGRAM;