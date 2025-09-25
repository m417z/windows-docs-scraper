NTSTATUS BCryptEnumAlgorithms(
  [in]  ULONG                       dwAlgOperations,
  [out] ULONG                       *pAlgCount,
  [out] BCRYPT_ALGORITHM_IDENTIFIER **ppAlgList,
  [in]  ULONG                       dwFlags
);