HRESULT CreateDevice(
  [in]           LPWSTR     pwszDeviceName,
                 DWORD      dwMode,
  [out]          PSTIDEVICE *pDevice,
  [in, optional] LPUNKNOWN  punkOuter
);