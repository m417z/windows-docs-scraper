SpValidateTargetInfoFn Spvalidatetargetinfofn;

NTSTATUS Spvalidatetargetinfofn(
  [in, optional] PLSA_CLIENT_REQUEST ClientRequest,
  [in]           PVOID ProtocolSubmitBuffer,
  [in]           PVOID ClientBufferBase,
  [in]           ULONG SubmitBufferLength,
  [in]           PSECPKG_TARGETINFO TargetInfo
)
{...}