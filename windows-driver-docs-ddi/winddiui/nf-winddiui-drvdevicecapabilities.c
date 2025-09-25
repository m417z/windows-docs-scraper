DWORD DrvDeviceCapabilities(
                 HANDLE   hPrinter,
  [in]           PWSTR    pszDeviceName,
                 WORD     Capability,
  [out]          PVOID    pOutput,
  [in, optional] PDEVMODE pDevmode
);