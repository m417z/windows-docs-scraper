typedef struct DOT11_PHY_ATTRIBUTES {
  NDIS_OBJECT_HEADER                  Header;
  DOT11_PHY_TYPE                      PhyType;
  BOOLEAN                             bHardwarePhyState;
  BOOLEAN                             bSoftwarePhyState;
  BOOLEAN                             bCFPollable;
  ULONG                               uMPDUMaxLength;
  DOT11_TEMP_TYPE                     TempType;
  DOT11_DIVERSITY_SUPPORT             DiversitySupport;
  union {
    DOT11_HRDSSS_PHY_ATTRIBUTES HRDSSSAttributes;
    DOT11_OFDM_PHY_ATTRIBUTES   OFDMAttributes;
    DOT11_ERP_PHY_ATTRIBUTES    ERPAttributes;
  };
  ULONG                               uNumberSupportedPowerLevels;
  ULONG                               TxPowerLevels[8];
  ULONG                               uNumDataRateMappingEntries;
  DOT11_DATA_RATE_MAPPING_ENTRY       DataRateMappingEntries[DOT11_RATE_SET_MAX_LENGTH];
  DOT11_SUPPORTED_DATA_RATES_VALUE_V2 SupportedDataRatesValue;
} DOT11_PHY_ATTRIBUTES, *PDOT11_PHY_ATTRIBUTES;