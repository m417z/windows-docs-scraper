DHPDEV DrvEnablePDEV(
  [in]           DEVMODEW *pdm,
  [in]           LPWSTR   pwszLogAddress,
                 ULONG    cPat,
  [in, optional] HSURF    *phsurfPatterns,
                 ULONG    cjCaps,
  [out]          ULONG    *pdevcaps,
                 ULONG    cjDevInfo,
  [out]          DEVINFO  *pdi,
                 HDEV     hdev,
  [in]           LPWSTR   pwszDeviceName,
                 HANDLE   hDriver
);