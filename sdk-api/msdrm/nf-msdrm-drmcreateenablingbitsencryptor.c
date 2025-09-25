DRMEXPORT HRESULT UDAPICALL DRMCreateEnablingBitsEncryptor(
  [in]           DRMHANDLE hBoundLicense,
  [in, optional] PWSTR     wszRight,
  [in]           DRMHANDLE hAuxLib,
  [in, optional] PWSTR     wszAuxPlug,
  [out]          DRMHANDLE *phEncryptor
);