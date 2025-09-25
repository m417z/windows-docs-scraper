NTSTATUS BCryptDeriveKeyPBKDF2(
  [in]           BCRYPT_ALG_HANDLE hPrf,
  [in, optional] PUCHAR            pbPassword,
  [in]           ULONG             cbPassword,
  [in, optional] PUCHAR            pbSalt,
  [in]           ULONG             cbSalt,
  [in]           ULONGLONG         cIterations,
  [out]          PUCHAR            pbDerivedKey,
  [in]           ULONG             cbDerivedKey,
  [in]           ULONG             dwFlags
);