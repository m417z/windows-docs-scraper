NTSTATUS NetIsServiceAccount(
  [in, optional] LPWSTR ServerName,
  [in]           LPWSTR AccountName,
  [out]          BOOL   *IsService
);