typedef struct _STOR_CRYPTO_OPERATION_INSERT_KEY {
  USHORT           Version;
  USHORT           Size;
  ULONG            KeyIndex;
  ULONG            CryptoCapabilityIndex;
  ULONG            DataUnitSizeBitmask;
  ULONG            KeySize;
  ULONG            Reserved;
  PVOID            KeyVirtualAddress;
  PHYSICAL_ADDRESS KeyPhysicalAddress;
} STOR_CRYPTO_OPERATION_INSERT_KEY, *PSTOR_CRYPTO_OPERATION_INSERT_KEY;