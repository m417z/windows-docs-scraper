NTSTATUS NetEnumerateServiceAccounts(
  [in, optional] LPWSTR  ServerName,
  [in]           DWORD   Flags,
  [out]          DWORD   *AccountsCount,
  [out]          PZPWSTR *Accounts
);