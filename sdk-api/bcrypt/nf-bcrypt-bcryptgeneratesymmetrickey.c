NTSTATUS BCryptGenerateSymmetricKey(
  [in, out]       BCRYPT_ALG_HANDLE hAlgorithm,
  [out]           BCRYPT_KEY_HANDLE *phKey,
  [out, optional] PUCHAR            pbKeyObject,
  [in]            ULONG             cbKeyObject,
  [in]            PUCHAR            pbSecret,
  [in]            ULONG             cbSecret,
  [in]            ULONG             dwFlags
);