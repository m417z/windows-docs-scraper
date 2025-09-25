NTDSAPI DWORD DsWriteAccountSpnA(
  [in] HANDLE          hDS,
  [in] DS_SPN_WRITE_OP Operation,
  [in] LPCSTR          pszAccount,
  [in] DWORD           cSpn,
  [in] LPCSTR          *rpszSpn
);