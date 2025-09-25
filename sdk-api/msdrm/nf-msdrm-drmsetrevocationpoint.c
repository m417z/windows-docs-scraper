DRMEXPORT HRESULT UDAPICALL DRMSetRevocationPoint(
  [in] DRMPUBHANDLE hIssuanceLicense,
  [in] BOOL         fDelete,
  [in] PWSTR        wszId,
  [in] PWSTR        wszIdType,
  [in] PWSTR        wszURL,
  [in] SYSTEMTIME   *pstFrequency,
  [in] PWSTR        wszName,
  [in] PWSTR        wszPublicKey
);