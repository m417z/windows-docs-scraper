typedef struct DOT11_HRDSSS_PHY_ATTRIBUTES {
  BOOLEAN bShortPreambleOptionImplemented;
  BOOLEAN bPBCCOptionImplemented;
  BOOLEAN bChannelAgilityPresent;
  ULONG   uHRCCAModeSupported;
} DOT11_HRDSSS_PHY_ATTRIBUTES, *PDOT11_HRDSSS_PHY_ATTRIBUTES;