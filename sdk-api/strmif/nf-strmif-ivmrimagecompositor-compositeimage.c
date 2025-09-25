HRESULT CompositeImage(
  [in] IUnknown             *pD3DDevice,
  [in] LPDIRECTDRAWSURFACE7 pddsRenderTarget,
  [in] AM_MEDIA_TYPE        *pmtRenderTarget,
  [in] REFERENCE_TIME       rtStart,
  [in] REFERENCE_TIME       rtEnd,
  [in] DWORD                dwClrBkGnd,
  [in] VMRVIDEOSTREAMINFO   *pVideoStreamInfo,
  [in] UINT                 cStreams
);