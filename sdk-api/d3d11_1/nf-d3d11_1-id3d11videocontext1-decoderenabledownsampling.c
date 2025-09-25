HRESULT DecoderEnableDownsampling(
  [in] ID3D11VideoDecoder            *pDecoder,
  [in] DXGI_COLOR_SPACE_TYPE         InputColorSpace,
  [in] const D3D11_VIDEO_SAMPLE_DESC *pOutputDesc,
  [in] UINT                          ReferenceFrameCount
);