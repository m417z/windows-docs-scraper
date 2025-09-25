NTSTATUS BCryptFinishHash(
  [in, out] BCRYPT_HASH_HANDLE hHash,
  [out]     PUCHAR             pbOutput,
  [in]      ULONG              cbOutput,
  [in]      ULONG              dwFlags
);