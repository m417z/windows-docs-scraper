NET_API_STATUS NET_API_FUNCTION NetRenameMachineInDomain(
  [in] LPCWSTR lpServer,
  [in] LPCWSTR lpNewMachineName,
  [in] LPCWSTR lpAccount,
  [in] LPCWSTR lpPassword,
  [in] DWORD   fRenameOptions
);