HRESULT GetCreationParameters(
  [out] GUID                      *pDeviceGuid,
  [out] DXVA2_VideoDesc           *pVideoDesc,
  [out] DXVA2_ConfigPictureDecode *pConfig,
  [out] IDirect3DSurface9         ***pDecoderRenderTargets,
  [out] UINT                      *pNumSurfaces
);