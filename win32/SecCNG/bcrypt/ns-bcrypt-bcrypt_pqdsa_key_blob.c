typedef struct _BCRYPT_PQDSA_KEY_BLOB {
  ULONG dwMagic;
  ULONG cbParameterSet;                                   // Byte size of parameterSet[]
  ULONG cbKey;                                            // Byte size of key[]
  // WCHAR parameterSet[cbParameterSet / sizeof(WCHAR)];  // Including \0 terminator
  // BYTE key[cbKey];                                     // Key material
} BCRYPT_PQDSA_KEY_BLOB, *PBCRYPT_PQDSA_KEY_BLOB;