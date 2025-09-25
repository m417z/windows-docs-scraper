NTSTATUS BCryptCreateMultiHash(
  BCRYPT_ALG_HANDLE  hAlgorithm,
  BCRYPT_HASH_HANDLE *phHash,
  ULONG              nHashes,
  PUCHAR             pbHashObject,
  ULONG              cbHashObject,
  PUCHAR             pbSecret,
  ULONG              cbSecret,
  ULONG              dwFlags
);