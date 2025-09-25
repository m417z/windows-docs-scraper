DRMEXPORT HRESULT UDAPICALL DRMGetUserInfo(
  [in]      DRMPUBHANDLE hUser,
  [in, out] UINT         *puUserNameLength,
  [out]     PWSTR        wszUserName,
  [in, out] UINT         *puUserIdLength,
  [out]     PWSTR        wszUserId,
  [in, out] UINT         *puUserIdTypeLength,
  [out]     PWSTR        wszUserIdType
);