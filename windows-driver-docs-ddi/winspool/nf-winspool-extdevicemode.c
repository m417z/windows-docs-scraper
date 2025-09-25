LONG ExtDeviceMode(
  [in, optional] HWND       hWnd,
  [in, optional] HANDLE     hInst,
  [in, out]      LPDEVMODEA pDevModeOutput,
  [in, optional] LPSTR      pDeviceName,
  [in, optional] LPSTR      pPort,
  [in, optional] LPDEVMODEA pDevModeInput,
  [in, optional] LPSTR      pProfile,
                 DWORD      fMode
);