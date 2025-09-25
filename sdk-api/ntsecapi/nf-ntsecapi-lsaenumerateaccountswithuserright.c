NTSTATUS LsaEnumerateAccountsWithUserRight(
  [in]  LSA_HANDLE          PolicyHandle,
  [in]  PLSA_UNICODE_STRING UserRight,
  [out] PVOID               *Buffer,
  [out] PULONG              CountReturned
);