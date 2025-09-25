NTSTATUS NetQueryServiceAccount(
  [in, optional] LPWSTR ServerName,
  [in]           LPWSTR AccountName,
  [in]           DWORD  InfoLevel,
  [out]          PBYTE  *Buffer
);