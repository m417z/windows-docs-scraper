SpInitLsaModeContextFn Spinitlsamodecontextfn;

NTSTATUS Spinitlsamodecontextfn(
  [in]  LSA_SEC_HANDLE CredentialHandle,
  [in]  LSA_SEC_HANDLE ContextHandle,
  [in]  PUNICODE_STRING TargetName,
  [in]  ULONG ContextRequirements,
  [in]  ULONG TargetDataRep,
  [in]  PSecBufferDesc InputBuffers,
  [out] PLSA_SEC_HANDLE NewContextHandle,
  [out] PSecBufferDesc OutputBuffers,
  [out] PULONG ContextAttributes,
  [out] PTimeStamp ExpirationTime,
  [out] PBOOLEAN MappedContext,
  [out] PSecBuffer ContextData
)
{...}