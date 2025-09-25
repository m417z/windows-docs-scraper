SpAcceptLsaModeContextFn Spacceptlsamodecontextfn;

NTSTATUS Spacceptlsamodecontextfn(
  [in]  LSA_SEC_HANDLE CredentialHandle,
  [in]  LSA_SEC_HANDLE ContextHandle,
  [in]  PSecBufferDesc InputBuffer,
  [in]  ULONG ContextRequirements,
  [in]  ULONG TargetDataRep,
  [out] PLSA_SEC_HANDLE NewContextHandle,
  [out] PSecBufferDesc OutputBuffer,
  [out] PULONG ContextAttributes,
  [out] PTimeStamp ExpirationTime,
  [out] PBOOLEAN MappedContext,
  [out] PSecBuffer ContextData
)
{...}