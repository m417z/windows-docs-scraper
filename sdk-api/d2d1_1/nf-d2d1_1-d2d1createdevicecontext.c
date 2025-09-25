HRESULT D2D1CreateDeviceContext(
  [in]           IDXGISurface                   *dxgiSurface,
  [in, optional] const D2D1_CREATION_PROPERTIES *creationProperties,
  [out]          ID2D1DeviceContext             **d2dDeviceContext
);