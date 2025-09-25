typedef struct _DOT11_SUPPORTED_OFDM_FREQUENCY_LIST {
  ULONG                          uNumOfEntries;
  ULONG                          uTotalNumOfEntries;
  DOT11_SUPPORTED_OFDM_FREQUENCY dot11SupportedOFDMFrequency[1];
} DOT11_SUPPORTED_OFDM_FREQUENCY_LIST, *PDOT11_SUPPORTED_OFDM_FREQUENCY_LIST;