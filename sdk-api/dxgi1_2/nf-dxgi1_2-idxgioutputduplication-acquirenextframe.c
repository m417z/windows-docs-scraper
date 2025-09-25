HRESULT AcquireNextFrame(
  [in]  UINT                    TimeoutInMilliseconds,
  [out] DXGI_OUTDUPL_FRAME_INFO *pFrameInfo,
  [out] IDXGIResource           **ppDesktopResource
);