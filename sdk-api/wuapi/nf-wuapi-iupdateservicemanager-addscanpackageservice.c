HRESULT AddScanPackageService(
  [in]  BSTR           serviceName,
  [in]  BSTR           scanFileLocation,
  [in]  LONG           flags,
  [out] IUpdateService **ppService
);