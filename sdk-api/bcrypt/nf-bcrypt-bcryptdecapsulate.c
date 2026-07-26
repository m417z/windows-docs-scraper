NTSTATUS BCryptDecapsulate(
  [in]  BCRYPT_KEY_HANDLE hKey,
  [in]  PUCHAR            pbCipherText,
  [in]  ULONG             cbCipherText,
  [out] PUCHAR            pbSecretKey,
  [in]  ULONG             cbSecretKey,
  [out] PULONG            pcbSecretKey,
  [in]  ULONG             dwFlags
);