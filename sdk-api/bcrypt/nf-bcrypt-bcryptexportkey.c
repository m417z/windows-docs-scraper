NTSTATUS BCryptExportKey(
  [in]  BCRYPT_KEY_HANDLE hKey,
  [in]  BCRYPT_KEY_HANDLE hExportKey,
  [in]  LPCWSTR           pszBlobType,
  [out] PUCHAR            pbOutput,
  [in]  ULONG             cbOutput,
  [out] ULONG             *pcbResult,
  [in]  ULONG             dwFlags
);