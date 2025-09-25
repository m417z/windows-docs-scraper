typedef struct _STORAGE_CRYPTO_DESCRIPTOR {
  ULONG                     Version;
  ULONG                     Size;
  ULONG                     NumKeysSupported;
  ULONG                     NumCryptoCapabilities;
  STORAGE_CRYPTO_CAPABILITY CryptoCapabilities[ANYSIZE_ARRAY];
} STORAGE_CRYPTO_DESCRIPTOR, *PSTORAGE_CRYPTO_DESCRIPTOR;