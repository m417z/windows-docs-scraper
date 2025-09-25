typedef struct _WWAN_NETWORK_PARAMS_INFO {
  WWAN_MICO_IND            CurrentMicoIndication;
  WWAN_DRX_PARAMS          CurrentDRXParams;
  WWAN_OFFSET_SIZE_ELEMENT TaiList;
  WWAN_OFFSET_SIZE_ELEMENT AllowedNssaiList;
  WWAN_OFFSET_SIZE_ELEMENT ConfiguredNssaiList;
  WWAN_OFFSET_SIZE_ELEMENT RejectedNssaiList;
  WWAN_OFFSET_SIZE_ELEMENT DefaultConfiguredNssaiList;
  WWAN_OFFSET_SIZE_ELEMENT LadnList;
  BYTE                     DataBuffer[ANYSIZE_ARRAY];
} WWAN_NETWORK_PARAMS_INFO, *PWWAN_NETWORK_PARAMS_INFO;