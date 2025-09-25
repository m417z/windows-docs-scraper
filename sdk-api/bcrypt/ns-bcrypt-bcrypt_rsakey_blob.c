typedef struct _BCRYPT_RSAKEY_BLOB {
  ULONG Magic;
  ULONG BitLength;
  ULONG cbPublicExp;
  ULONG cbModulus;
  ULONG cbPrime1;
  ULONG cbPrime2;
} BCRYPT_RSAKEY_BLOB;