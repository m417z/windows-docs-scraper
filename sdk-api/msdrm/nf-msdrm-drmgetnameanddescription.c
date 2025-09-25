DRMEXPORT HRESULT UDAPICALL DRMGetNameAndDescription(
  [in]      DRMPUBHANDLE hIssuanceLicense,
  [in]      UINT         uIndex,
  [out]     UINT         *pulcid,
  [in, out] UINT         *puNameLength,
  [out]     PWSTR        wszName,
  [in, out] UINT         *puDescriptionLength,
  [out]     PWSTR        wszDescription
);