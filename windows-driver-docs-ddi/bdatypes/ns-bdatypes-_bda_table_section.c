typedef struct _BDA_TABLE_SECTION {
  ULONG ulPrimarySectionId;
  ULONG ulSecondarySectionId;
  ULONG ulcbSectionLength;
  ULONG argbSectionData[MIN_DIMENSION];
} BDA_TABLE_SECTION, *PBDA_TABLE_SECTION;