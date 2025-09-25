SECURITY_STATUS SspiAcquireCredentialsHandleAsyncA(
  SspiAsyncContext *AsyncContext,
  LPSTR            pszPrincipal,
  LPSTR            pszPackage,
  unsigned long    fCredentialUse,
  void             *pvLogonId,
  void             *pAuthData,
  SEC_GET_KEY_FN   pGetKeyFn,
  void             *pvGetKeyArgument,
  PCredHandle      phCredential,
  PTimeStamp       ptsExpiry
);