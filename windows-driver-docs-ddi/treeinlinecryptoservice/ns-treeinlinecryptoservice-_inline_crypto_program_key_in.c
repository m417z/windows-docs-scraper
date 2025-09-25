typedef struct _INLINE_CRYPTO_PROGRAM_KEY_IN {
  ULONG                        KeyIndex;
  ULONG                        CryptoCapabilityIndex;
  INLINE_CRYPTO_DATA_UNIT_SIZE DataUnitSize;
  ULONG                        KeySize;
  PVOID                        KeyVirtualAddress;
  PHYSICAL_ADDRESS             KeyPhysicalAddress;
} INLINE_CRYPTO_PROGRAM_KEY_IN, *PINLINE_CRYPTO_PROGRAM_KEY_IN;