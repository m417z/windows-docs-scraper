KSECDDDECLSPEC SECURITY_STATUS SEC_ENTRY AcquireCredentialsHandleW(
                  PSECURITY_STRING pPrincipal,
                  PSECURITY_STRING pPackage,
  [in]            unsigned long    fCredentialUse,
  [in, optional]  void             *pvLogonId,
  [in, optional]  void             *pAuthData,
  [in, optional]  SEC_GET_KEY_FN   pGetKeyFn,
  [in, optional]  void             *pvGetKeyArgument,
  [out]           PCredHandle      phCredential,
  [out, optional] PTimeStamp       ptsExpiry
);