typedef struct _BCRYPT_DSA_KEY_BLOB {
  ULONG dwMagic;
  ULONG cbKey;
  UCHAR Count[4];
  UCHAR Seed[20];
  UCHAR q[20];
} BCRYPT_DSA_KEY_BLOB, *PBCRYPT_DSA_KEY_BLOB;