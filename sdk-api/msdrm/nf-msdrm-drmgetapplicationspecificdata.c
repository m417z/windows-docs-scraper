DRMEXPORT HRESULT UDAPICALL DRMGetApplicationSpecificData(
  [in]      DRMPUBHANDLE hIssuanceLicense,
  [in]      UINT         uIndex,
  [in, out] UINT         *puNameLength,
  [out]     PWSTR        wszName,
  [in, out] UINT         *puValueLength,
  [out]     PWSTR        wszValue
);