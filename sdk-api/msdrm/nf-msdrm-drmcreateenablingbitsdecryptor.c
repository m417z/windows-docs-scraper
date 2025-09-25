DRMEXPORT HRESULT UDAPICALL DRMCreateEnablingBitsDecryptor(
  [in]           DRMHANDLE hBoundLicense,
  [in, optional] PWSTR     wszRight,
  [in]           DRMHANDLE hAuxLib,
  [in, optional] PWSTR     wszAuxPlug,
  [out]          DRMHANDLE *phDecryptor
);