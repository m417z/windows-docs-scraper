typedef struct _STOR_CRYPTO_CAPABILITIES_DATA {
  ULONG                  Version;
  ULONG                  Size;
  USHORT                 NumKeysSupported;
  USHORT                 NumCryptoCapabilities;
  STOR_CRYPTO_CAPABILITY CryptoCapabilities[ANYSIZE_ARRAY];
} STOR_CRYPTO_CAPABILITIES_DATA, *PSTOR_CRYPTO_CAPABILITIES_DATA;