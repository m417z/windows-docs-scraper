HRESULT UploadPrinterDriverPackage(
  _In_    LPCTSTR pszServer,
  _In_    LPCTSTR pszInfPath,
  _In_    LPCTSTR pszEnvironment,
  _In_    DWORD   dwFlags,
  _In_    HWND    hwnd,
  _Out_   LPTSTR  pszDestInfPath,
  _Inout_ PULONG  pcchDestInfPath
);