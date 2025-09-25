DRMEXPORT HRESULT UDAPICALL DRMGetProcAddress(
  [in]  DRMHANDLE hLibrary,
  [in]  PWSTR     wszProcName,
  [out] FARPROC   *ppfnProcAddress
);