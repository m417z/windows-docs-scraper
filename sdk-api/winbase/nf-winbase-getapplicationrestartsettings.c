HRESULT GetApplicationRestartSettings(
  [in]            HANDLE hProcess,
  [out, optional] PWSTR  pwzCommandline,
  [in, out]       PDWORD pcchSize,
  [out, optional] PDWORD pdwFlags
);