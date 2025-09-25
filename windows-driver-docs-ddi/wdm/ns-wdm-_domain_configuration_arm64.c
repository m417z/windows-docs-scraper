typedef struct _DOMAIN_CONFIGURATION_ARM64 {
  PHYSICAL_ADDRESS Ttbr0;
  PHYSICAL_ADDRESS Ttbr1;
  ULONG            Mair0;
  ULONG            Mair1;
  UCHAR            InputSize0;
  UCHAR            InputSize1;
  BOOLEAN          CoherentTableWalks;
  BOOLEAN          TranslationEnabled;
} DOMAIN_CONFIGURATION_ARM64, *PDOMAIN_CONFIGURATION_ARM64;