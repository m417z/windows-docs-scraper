typedef struct KERB_CRYPTO_KEY {
  LONG   KeyType;
  ULONG  Length;
  PUCHAR Value;
} KERB_CRYPTO_KEY, *PKERB_CRYPTO_KEY;