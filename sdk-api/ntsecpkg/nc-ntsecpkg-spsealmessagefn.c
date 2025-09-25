SpSealMessageFn Spsealmessagefn;

NTSTATUS Spsealmessagefn(
  [in]      LSA_SEC_HANDLE ContextHandle,
  [in]      ULONG QualityOfProtection,
  [in, out] PSecBufferDesc MessageBuffers,
  [in]      ULONG MessageSequenceNumber
)
{...}