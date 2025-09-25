typedef struct _IPSEC_KEY_MANAGER0 {
  GUID               keyManagerKey;
  FWPM_DISPLAY_DATA0 displayData;
  UINT32             flags;
  UINT8              keyDictationTimeoutHint;
} IPSEC_KEY_MANAGER0;