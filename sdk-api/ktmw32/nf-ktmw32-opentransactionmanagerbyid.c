HANDLE OpenTransactionManagerById(
  [in]           LPGUID      TransactionManagerId,
  [in]           ACCESS_MASK DesiredAccess,
  [in, optional] ULONG       OpenOptions
);