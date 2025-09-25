typedef struct _STOR_CRYPTO_KEY_INFO {
  ULONG     Version;
  ULONG     Size;
  ULONG     KeyIndex;
  ULONGLONG Tweak;
} STOR_CRYPTO_KEY_INFO, *PSTOR_CRYPTO_KEY_INFO;