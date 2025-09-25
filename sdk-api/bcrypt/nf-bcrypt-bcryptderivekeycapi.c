NTSTATUS BCryptDeriveKeyCapi(
  [in]           BCRYPT_HASH_HANDLE hHash,
  [in, optional] BCRYPT_ALG_HANDLE  hTargetAlg,
  [out]          PUCHAR             pbDerivedKey,
  [in]           ULONG              cbDerivedKey,
  [in]           ULONG              dwFlags
);