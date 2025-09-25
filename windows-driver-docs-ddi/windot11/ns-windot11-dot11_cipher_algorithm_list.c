typedef struct DOT11_CIPHER_ALGORITHM_LIST {
  NDIS_OBJECT_HEADER     Header;
  ULONG                  uNumOfEntries;
  ULONG                  uTotalNumOfEntries;
  DOT11_CIPHER_ALGORITHM AlgorithmIds[1];
} DOT11_CIPHER_ALGORITHM_LIST, *PDOT11_CIPHER_ALGORITHM_LIST;