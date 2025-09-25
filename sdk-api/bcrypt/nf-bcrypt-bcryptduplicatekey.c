NTSTATUS BCryptDuplicateKey(
  [in]  BCRYPT_KEY_HANDLE hKey,
  [out] BCRYPT_KEY_HANDLE *phNewKey,
  [out] PUCHAR            pbKeyObject,
  [in]  ULONG             cbKeyObject,
  [in]  ULONG             dwFlags
);