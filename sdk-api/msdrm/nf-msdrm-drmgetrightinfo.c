DRMEXPORT HRESULT UDAPICALL DRMGetRightInfo(
  [in]      DRMPUBHANDLE hRight,
  [in, out] UINT         *puRightNameLength,
  [out]     PWSTR        wszRightName,
  [out]     SYSTEMTIME   *pstFrom,
  [out]     SYSTEMTIME   *pstUntil
);