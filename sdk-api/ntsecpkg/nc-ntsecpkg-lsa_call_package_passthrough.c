LSA_CALL_PACKAGE_PASSTHROUGH LsaCallPackagePassthrough;

NTSTATUS LsaCallPackagePassthrough(
  [in]  PUNICODE_STRING AuthenticationPackage,
  [in]  PVOID ClientBufferBase,
  [in]  PVOID ProtocolSubmitBuffer,
  [in]  ULONG SubmitBufferLength,
  [out] PVOID *ProtocolReturnBuffer,
  [out] PULONG ReturnBufferLength,
  [out] PNTSTATUS ProtocolStatus
)
{...}