KspVerifySignatureFn Kspverifysignaturefn;

NTSTATUS Kspverifysignaturefn(
        LSA_SEC_HANDLE ContextId,
  [in]  PSecBufferDesc Message,
  [in]  ULONG MessageSeqNo,
  [out] PULONG pfQOP
)
{...}