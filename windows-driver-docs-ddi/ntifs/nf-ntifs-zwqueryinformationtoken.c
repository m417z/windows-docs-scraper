NTSYSAPI NTSTATUS ZwQueryInformationToken(
  [in]  HANDLE                  TokenHandle,
  [in]  TOKEN_INFORMATION_CLASS TokenInformationClass,
  [out] PVOID                   TokenInformation,
  [in]  ULONG                   TokenInformationLength,
  [out] PULONG                  ReturnLength
);