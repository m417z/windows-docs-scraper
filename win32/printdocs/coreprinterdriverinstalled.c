HRESULT CorePrinterDriverInstalled(
  _In_  LPCTSTR   pszServer,
  _In_  LPCTSTR   pszEnvironment,
  _In_  GUID      CoreDriverGUID,
  _In_  FILETIME  ftDriverDate,
  _In_  DWORDLONG dwlDriverVersion,
  _Out_ BOOL      *pbDriverInstalled
);