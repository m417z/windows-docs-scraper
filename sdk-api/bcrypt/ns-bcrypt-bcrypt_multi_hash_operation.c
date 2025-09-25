typedef struct _BCRYPT_MULTI_HASH_OPERATION {
  ULONG                      iHash;
  BCRYPT_HASH_OPERATION_TYPE hashOperation;
  PUCHAR                     pbBuffer;
  ULONG                      cbBuffer;
} BCRYPT_MULTI_HASH_OPERATION;