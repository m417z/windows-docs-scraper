HRESULT CreateVideoDecoder(
  [in]  REFGUID                         Guid,
  [in]  const DXVA2_VideoDesc           *pVideoDesc,
  [in]  const DXVA2_ConfigPictureDecode *pConfig,
  [in]  IDirect3DSurface9               **ppDecoderRenderTargets,
  [in]  UINT                            NumRenderTargets,
  [out] IDirectXVideoDecoder            **ppDecode
);