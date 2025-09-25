SECURITY_STATUS NCryptEnumAlgorithms(
  [in]  NCRYPT_PROV_HANDLE  hProvider,
  [in]  DWORD               dwAlgOperations,
  [out] DWORD               *pdwAlgCount,
  [out] NCryptAlgorithmName **ppAlgList,
  [in]  DWORD               dwFlags
);