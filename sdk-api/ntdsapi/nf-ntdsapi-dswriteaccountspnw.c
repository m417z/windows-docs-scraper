NTDSAPI DWORD DsWriteAccountSpnW(
  [in] HANDLE          hDS,
  [in] DS_SPN_WRITE_OP Operation,
  [in] LPCWSTR         pszAccount,
  [in] DWORD           cSpn,
  [in] LPCWSTR         *rpszSpn
);