SpAcquireCredentialsHandleFn Spacquirecredentialshandlefn;

NTSTATUS Spacquirecredentialshandlefn(
  [in]  PUNICODE_STRING PrincipalName,
  [in]  ULONG CredentialUseFlags,
  [in]  PLUID LogonId,
  [in]  PVOID AuthorizationData,
        PVOID GetKeyFunciton,
  [in]  PVOID GetKeyArgument,
  [out] PLSA_SEC_HANDLE CredentialHandle,
  [out] PTimeStamp ExpirationTime
)
{...}