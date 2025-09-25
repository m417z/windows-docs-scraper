typedef struct _CRYPT_BIT_BLOB {
  DWORD cbData;
  BYTE  *pbData;
  DWORD cUnusedBits;
} CRYPT_BIT_BLOB, *PCRYPT_BIT_BLOB;