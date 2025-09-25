typedef struct _NFC_CX_RF_DISCOVERY_CONFIG {
  ULONG  Size;
  USHORT TotalDuration;
  ULONG  PollConfig;
  UCHAR  NfcIPMode;
  UCHAR  NfcIPTgtMode;
  UCHAR  NfcCEMode;
  UCHAR  BailoutConfig;
} NFC_CX_RF_DISCOVERY_CONFIG, *PNFC_CX_RF_DISCOVERY_CONFIG;