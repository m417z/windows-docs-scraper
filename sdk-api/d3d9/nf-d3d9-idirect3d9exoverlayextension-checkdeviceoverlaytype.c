HRESULT CheckDeviceOverlayType(
  [in]  UINT               Adapter,
  [in]  D3DDEVTYPE         DevType,
  [in]  UINT               OverlayWidth,
  [in]  UINT               OverlayHeight,
  [in]  D3DFORMAT          OverlayFormat,
  [in]  D3DDISPLAYMODEEX   *pDisplayMode,
  [in]  D3DDISPLAYROTATION DisplayRotation,
  [out] D3DOVERLAYCAPS     *pOverlayCaps
);