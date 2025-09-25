NTSTATUS BCryptDuplicateHash(
  [in]            BCRYPT_HASH_HANDLE hHash,
  [out]           BCRYPT_HASH_HANDLE *phNewHash,
  [out, optional] PUCHAR             pbHashObject,
  [in]            ULONG              cbHashObject,
  [in]            ULONG              dwFlags
);