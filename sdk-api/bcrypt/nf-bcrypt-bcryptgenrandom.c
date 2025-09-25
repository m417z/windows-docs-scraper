NTSTATUS BCryptGenRandom(
  [in, out] BCRYPT_ALG_HANDLE hAlgorithm,
  [in, out] PUCHAR            pbBuffer,
  [in]      ULONG             cbBuffer,
  [in]      ULONG             dwFlags
);