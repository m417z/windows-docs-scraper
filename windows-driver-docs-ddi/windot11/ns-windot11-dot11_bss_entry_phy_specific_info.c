typedef union DOT11_BSS_ENTRY_PHY_SPECIFIC_INFO {
  ULONG  uChCenterFrequency;
  struct {
    ULONG uHopPattern;
    ULONG uHopSet;
    ULONG uDwellTime;
  } FHSS;
} DOT11_BSS_ENTRY_PHY_SPECIFIC_INFO, *PDOT11_BSS_ENTRY_PHY_SPECIFIC_INFO;