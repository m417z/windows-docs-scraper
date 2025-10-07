NTSTATUS BCryptEncapsulate(
  _In_  BCRYPT_KEY_HANDLE hKey,
  _Out_writes_bytes_to_opt_(cbSecretKey ,*pcbSecretKey)
        PUCHAR            pbSecretKey,
  _In_  ULONG             cbSecretKey,
  _Out_ ULONG             *pcbSecretKey,
  _Out_writes_bytes_to_opt_(cbCipherText ,*pcbCipherText)
        PUCHAR            pbCipherText,
  _In_  ULONG             cbCipherText,
  _Out_ ULONG             *pcbCipherText,
  _In_  ULONG             dwFlags
);