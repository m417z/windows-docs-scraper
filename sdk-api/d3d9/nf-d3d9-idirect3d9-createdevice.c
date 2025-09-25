HRESULT CreateDevice(
  [in]          UINT                  Adapter,
  [in]          D3DDEVTYPE            DeviceType,
  [in]          HWND                  hFocusWindow,
  [in]          DWORD                 BehaviorFlags,
  [in, out]     D3DPRESENT_PARAMETERS *pPresentationParameters,
  [out, retval] IDirect3DDevice9      **ppReturnedDeviceInterface
);