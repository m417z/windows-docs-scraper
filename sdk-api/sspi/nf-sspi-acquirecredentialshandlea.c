SECURITY_STATUS SEC_ENTRY AcquireCredentialsHandleA(
  [in, optional]  LPSTR          pszPrincipal,
  [in]            LPSTR          pszPackage,
  [in]            unsigned long  fCredentialUse,
  [in, optional]  void           *pvLogonId,
  [in, optional]  void           *pAuthData,
  [in, optional]  SEC_GET_KEY_FN pGetKeyFn,
  [in, optional]  void           *pvGetKeyArgument,
  [out]           PCredHandle    phCredential,
  [out, optional] PTimeStamp     ptsExpiry
);