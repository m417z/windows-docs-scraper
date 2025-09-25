KspMakeSignatureFn Kspmakesignaturefn;

NTSTATUS Kspmakesignaturefn(
  [in] LSA_SEC_HANDLE ContextId,
  [in] ULONG fQOP,
  [in] PSecBufferDesc Message,
  [in] ULONG MessageSeqNo
)
{...}