NTSTATUS BCryptImportKey(
  [in]            BCRYPT_ALG_HANDLE hAlgorithm,
  [in, optional]  BCRYPT_KEY_HANDLE hImportKey,
  [in]            LPCWSTR           pszBlobType,
  [out]           BCRYPT_KEY_HANDLE *phKey,
  [out, optional] PUCHAR            pbKeyObject,
  [in]            ULONG             cbKeyObject,
  [in]            PUCHAR            pbInput,
  [in]            ULONG             cbInput,
  [in]            ULONG             dwFlags
);