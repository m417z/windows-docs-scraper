DRMEXPORT HRESULT UDAPICALL DRMCreateRight(
  [in]  PWSTR        wszRightName,
  [in]  SYSTEMTIME   *pstFrom,
  [in]  SYSTEMTIME   *pstUntil,
  [in]  UINT         cExtendedInfo,
  [in]  PWSTR        *pwszExtendedInfoName,
  [in]  PWSTR        *pwszExtendedInfoValue,
  [out] DRMPUBHANDLE *phRight
);