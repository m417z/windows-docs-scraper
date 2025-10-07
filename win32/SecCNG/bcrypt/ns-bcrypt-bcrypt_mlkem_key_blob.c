typedef struct _BCRYPT_MLKEM_KEY_BLOB {
  ULONG dwMagic;
  ULONG cbParameterSet;             // Byte size of parameterSet[]
  ULONG cbKey;                      // Byte size of key[]
  // WCHAR parameterSet[cbParameterSet / sizeof(WCHAR)];  // Including \0-terminated
  // BYTE key[cbKey];                                     // Key material
} BCRYPT_MLKEM_KEY_BLOB, *PBCRYPT_MLKEM_KEY_BLOB;