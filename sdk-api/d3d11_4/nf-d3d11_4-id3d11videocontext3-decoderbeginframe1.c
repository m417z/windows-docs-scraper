HRESULT DecoderBeginFrame1(
  ID3D11VideoDecoder           *pDecoder,
  ID3D11VideoDecoderOutputView *pView,
  UINT                         ContentKeySize,
  const void                   *pContentKey,
  UINT                         NumComponentHistograms,
  const UINT                   *pHistogramOffsets,
  ID3D11Buffer                 * const *ppHistogramBuffers
);