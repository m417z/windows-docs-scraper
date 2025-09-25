NTSTATUS BCryptCreateHash(
  [in, out]       BCRYPT_ALG_HANDLE  hAlgorithm,
  [out]           BCRYPT_HASH_HANDLE *phHash,
  [out, optional] PUCHAR             pbHashObject,
  [in]            ULONG              cbHashObject,
  [in, optional]  PUCHAR             pbSecret,
  [in]            ULONG              cbSecret,
  [in]            ULONG              dwFlags
);