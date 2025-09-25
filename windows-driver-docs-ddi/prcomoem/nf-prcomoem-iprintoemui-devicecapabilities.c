HRESULT DeviceCapabilities(
  POEMUIOBJ poemuiobj,
  HANDLE    hPrinter,
  PWSTR     pDeviceName,
  WORD      wCapability,
  PVOID     pOutput,
  PDEVMODE  pPublicDM,
  PVOID     pOEMDM,
  DWORD     dwOld,
  DWORD     *dwResult
);