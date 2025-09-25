NTSTATUS LsaCallAuthenticationPackage(
  [in]  HANDLE    LsaHandle,
  [in]  ULONG     AuthenticationPackage,
  [in]  PVOID     ProtocolSubmitBuffer,
  [in]  ULONG     SubmitBufferLength,
  [out] PVOID     *ProtocolReturnBuffer,
  [out] PULONG    ReturnBufferLength,
  [out] PNTSTATUS ProtocolStatus
);