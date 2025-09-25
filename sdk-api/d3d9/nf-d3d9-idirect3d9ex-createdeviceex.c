HRESULT CreateDeviceEx(
  [in]          UINT                  Adapter,
  [in]          D3DDEVTYPE            DeviceType,
  [in]          HWND                  hFocusWindow,
  [in]          DWORD                 BehaviorFlags,
  [in, out]     D3DPRESENT_PARAMETERS *pPresentationParameters,
  [in, out]     D3DDISPLAYMODEEX      *pFullscreenDisplayMode,
  [out, retval] IDirect3DDevice9Ex    **ppReturnedDeviceInterface
);