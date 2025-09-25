LSA_AP_CALL_PACKAGE_PASSTHROUGH LsaApCallPackagePassthrough;

NTSTATUS LsaApCallPackagePassthrough(
  [in]  PLSA_CLIENT_REQUEST ClientRequest,
  [in]  PVOID ProtocolSubmitBuffer,
  [in]  PVOID ClientBufferBase,
  [in]  ULONG SubmitBufferLength,
  [out] PVOID *ProtocolReturnBuffer,
  [out] PULONG ReturnBufferLength,
  [out] PNTSTATUS ProtocolStatus
)
{...}