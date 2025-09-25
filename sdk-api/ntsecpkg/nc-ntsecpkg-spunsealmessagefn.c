SpUnsealMessageFn Spunsealmessagefn;

NTSTATUS Spunsealmessagefn(
  [in]  LSA_SEC_HANDLE ContextHandle,
  [in]  PSecBufferDesc MessageBuffers,
  [in]  ULONG MessageSequenceNumber,
  [out] PULONG QualityOfProtection
)
{...}