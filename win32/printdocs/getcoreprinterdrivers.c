HRESULT GetCorePrinterDrivers(
  _In_  LPCTSTR              pszServer,
  _In_  LPCTSTR              pszEnvironment,
  _In_  LPCTSTR              pszzCoreDriverDependencies,
  _In_  DWORD                cCorePrinterDrivers,
  _Out_ PCORE_PRINTER_DRIVER pCorePrinterDrivers
);