typedef struct DOT11_ERP_PHY_ATTRIBUTES {
  DOT11_HRDSSS_PHY_ATTRIBUTES HRDSSSAttributes;
  BOOLEAN                     bERPPBCCOptionImplemented;
  BOOLEAN                     bDSSSOFDMOptionImplemented;
  BOOLEAN                     bShortSlotTimeOptionImplemented;
} DOT11_ERP_PHY_ATTRIBUTES, *PDOT11_ERP_PHY_ATTRIBUTES;