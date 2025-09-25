typedef struct _BCRYPT_DSA_PARAMETER_HEADER {
  ULONG cbLength;
  ULONG dwMagic;
  ULONG cbKeyLength;
  UCHAR Count[4];
  UCHAR Seed[20];
  UCHAR q[20];
} BCRYPT_DSA_PARAMETER_HEADER;