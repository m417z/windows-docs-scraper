NTSTATUS BCryptEncapsulate(
  [in]  BCRYPT_KEY_HANDLE hKey,
  [out] PUCHAR            pbSecretKey,
  [in]  ULONG             cbSecretKey,
  [out] PULONG            pcbSecretKey,
  [out] PUCHAR            pbCipherText,
  [in]  ULONG             cbCipherText,
  [out] PULONG            pcbCipherText,
  [in]  ULONG             dwFlags
);