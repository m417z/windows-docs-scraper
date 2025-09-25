SECURITY_STATUS SEC_ENTRY AddCredentialsA(
  PCredHandle    hCredentials,
  LPSTR          pszPrincipal,
  LPSTR          pszPackage,
  unsigned long  fCredentialUse,
  void           *pAuthData,
  SEC_GET_KEY_FN pGetKeyFn,
  void           *pvGetKeyArgument,
  PTimeStamp     ptsExpiry
);