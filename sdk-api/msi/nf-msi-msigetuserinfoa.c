USERINFOSTATE MsiGetUserInfoA(
  [in]      LPCSTR  szProduct,
  [out]     LPSTR   lpUserNameBuf,
  [in, out] LPDWORD pcchUserNameBuf,
  [out]     LPSTR   lpOrgNameBuf,
  [in, out] LPDWORD pcchOrgNameBuf,
  [in]      LPSTR   lpSerialBuf,
  [in, out] LPDWORD pcchSerialBuf
);