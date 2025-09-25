KSECDDDECLSPEC SECURITY_STATUS SEC_ENTRY AddCredentialsW(
  PCredHandle      hCredentials,
  PSECURITY_STRING pPrincipal,
  PSECURITY_STRING pPackage,
  unsigned long    fCredentialUse,
  void             *pAuthData,
  SEC_GET_KEY_FN   pGetKeyFn,
  void             *pvGetKeyArgument,
  PTimeStamp       ptsExpiry
);