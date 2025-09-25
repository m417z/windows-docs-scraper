NTSTATUS BCryptOpenAlgorithmProvider(
  [out]          BCRYPT_ALG_HANDLE *phAlgorithm,
  [in]           LPCWSTR           pszAlgId,
  [in, optional] LPCWSTR           pszImplementation,
  [in]           ULONG             dwFlags
);