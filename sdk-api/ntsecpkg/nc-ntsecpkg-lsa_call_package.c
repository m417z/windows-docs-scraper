LSA_CALL_PACKAGE LsaCallPackage;

NTSTATUS LsaCallPackage(
  [in]  PUNICODE_STRING AuthenticationPackage,
  [in]  PVOID ProtocolSubmitBuffer,
  [in]  ULONG SubmitBufferLength,
  [out] PVOID *ProtocolReturnBuffer,
  [out] PULONG ReturnBufferLength,
  [out] PNTSTATUS ProtocolStatus
)
{...}