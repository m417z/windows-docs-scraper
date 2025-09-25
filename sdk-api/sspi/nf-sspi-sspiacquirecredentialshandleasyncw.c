SECURITY_STATUS SspiAcquireCredentialsHandleAsyncW(
  SspiAsyncContext *AsyncContext,
  PSECURITY_STRING pszPrincipal,
  PSECURITY_STRING pszPackage,
  unsigned long    fCredentialUse,
  void             *pvLogonId,
  void             *pAuthData,
  SEC_GET_KEY_FN   pGetKeyFn,
  void             *pvGetKeyArgument,
  PCredHandle      phCredential,
  PTimeStamp       ptsExpiry
);