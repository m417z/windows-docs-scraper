NET_API_STATUS NET_API_FUNCTION NetRemoveAlternateComputerName(
  [in, optional] LPCWSTR Server,
  [in]           LPCWSTR AlternateName,
  [in, optional] LPCWSTR DomainAccount,
  [in, optional] LPCWSTR DomainAccountPassword,
  [in]           ULONG   Reserved
);