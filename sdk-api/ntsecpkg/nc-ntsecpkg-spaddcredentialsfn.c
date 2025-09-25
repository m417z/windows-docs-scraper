SpAddCredentialsFn Spaddcredentialsfn;

NTSTATUS Spaddcredentialsfn(
  [in]  LSA_SEC_HANDLE CredentialHandle,
  [in]  PUNICODE_STRING PrincipalName,
  [in]  PUNICODE_STRING Package,
  [in]  ULONG CredentialUseFlags,
  [in]  PVOID AuthorizationData,
        PVOID GetKeyFunciton,
  [in]  PVOID GetKeyArgument,
  [out] PTimeStamp ExpirationTime
)
{...}