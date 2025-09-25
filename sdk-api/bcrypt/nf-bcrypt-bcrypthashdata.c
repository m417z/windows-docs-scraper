NTSTATUS BCryptHashData(
  [in, out] BCRYPT_HASH_HANDLE hHash,
  [in]      PUCHAR             pbInput,
  [in]      ULONG              cbInput,
  [in]      ULONG              dwFlags
);