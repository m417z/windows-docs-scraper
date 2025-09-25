USERINFOSTATE MsiGetUserInfoW(
  [in]      LPCWSTR szProduct,
  [out]     LPWSTR  lpUserNameBuf,
  [in, out] LPDWORD pcchUserNameBuf,
  [out]     LPWSTR  lpOrgNameBuf,
  [in, out] LPDWORD pcchOrgNameBuf,
  [in]      LPWSTR  lpSerialBuf,
  [in, out] LPDWORD pcchSerialBuf
);