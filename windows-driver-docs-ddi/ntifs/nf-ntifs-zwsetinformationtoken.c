NTSYSAPI NTSTATUS ZwSetInformationToken(
  [in] HANDLE                  TokenHandle,
  [in] TOKEN_INFORMATION_CLASS TokenInformationClass,
  [in] PVOID                   TokenInformation,
  [in] ULONG                   TokenInformationLength
);