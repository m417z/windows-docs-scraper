NTSTATUS BCryptHash(
  [in, out]      BCRYPT_ALG_HANDLE hAlgorithm,
  [in, optional] PUCHAR            pbSecret,
  [in]           ULONG             cbSecret,
  [in]           PUCHAR            pbInput,
  [in]           ULONG             cbInput,
  [out]          PUCHAR            pbOutput,
  [in]           ULONG             cbOutput
);