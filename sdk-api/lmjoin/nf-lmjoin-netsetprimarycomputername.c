NET_API_STATUS NET_API_FUNCTION NetSetPrimaryComputerName(
  [in, optional] LPCWSTR Server,
  [in]           LPCWSTR PrimaryName,
  [in, optional] LPCWSTR DomainAccount,
  [in, optional] LPCWSTR DomainAccountPassword,
  [in]           ULONG   Reserved
);