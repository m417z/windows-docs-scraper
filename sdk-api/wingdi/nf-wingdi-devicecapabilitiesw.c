int DeviceCapabilitiesW(
  [in]  LPCWSTR        pDevice,
  [in]  LPCWSTR        pPort,
  [in]  WORD           fwCapability,
  [out] LPWSTR         pOutput,
  [in]  const DEVMODEW *pDevMode
);