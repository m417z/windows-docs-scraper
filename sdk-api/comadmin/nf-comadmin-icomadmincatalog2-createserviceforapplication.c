HRESULT CreateServiceForApplication(
  [in] BSTR         bstrApplicationIDOrName,
  [in] BSTR         bstrServiceName,
  [in] BSTR         bstrStartType,
  [in] BSTR         bstrErrorControl,
  [in] BSTR         bstrDependencies,
  [in] BSTR         bstrRunAs,
  [in] BSTR         bstrPassword,
  [in] VARIANT_BOOL bDesktopOk
);