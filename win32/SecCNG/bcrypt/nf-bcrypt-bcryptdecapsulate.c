NTSTATUS BCryptDecapsulate(
  _In_  BCRYPT_KEY_HANDLE hKey,
  _In_reads_bytes_(cbCipherText)
        PUCHAR            pbCipherText,
  _In_  ULONG             cbCipherText,
  _Out_writes_bytes_to_opt_(cbSecretKey, *pcbSecretKey)
        PUCHAR            pbSecretKey,
  _In_  ULONG             cbSecretKey,
  _Out_ ULONG             *pcbSecretKey,
  _In_  ULONG             dwFlags
);