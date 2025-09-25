DRMEXPORT HRESULT UDAPICALL DRMGetRevocationPoint(
  [in]      DRMPUBHANDLE hIssuanceLicense,
  [in, out] UINT         *puIdLength,
  [out]     PWSTR        wszId,
  [in, out] UINT         *puIdTypeLength,
  [out]     PWSTR        wszIdType,
  [in, out] UINT         *puURLLength,
  [out]     PWSTR        wszRL,
  [out]     SYSTEMTIME   *pstFrequency,
  [in, out] UINT         *puNameLength,
  [out]     PWSTR        wszName,
  [in, out] UINT         *puPublicKeyLength,
  [out]     PWSTR        wszPublicKey
);