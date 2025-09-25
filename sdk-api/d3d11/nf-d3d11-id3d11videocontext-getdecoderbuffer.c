HRESULT GetDecoderBuffer(
  [in]  ID3D11VideoDecoder              *pDecoder,
  [in]  D3D11_VIDEO_DECODER_BUFFER_TYPE Type,
  [out] UINT                            *pBufferSize,
  [out] void                            **ppBuffer
);