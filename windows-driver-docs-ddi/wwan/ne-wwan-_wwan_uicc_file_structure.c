typedef enum _WWAN_UICC_FILE_STRUCTURE {
  WwanUiccFileStructureUnknown,
  WwanUiccFileStructureTransparent,
  WwanUiccFileStructureCyclic,
  WwanUiccFileStructureLinear,
  WwanUiccFileStructureBerTLV,
  WwanUiccFileStructureMax
} WWAN_UICC_FILE_STRUCTURE, *PWWAN_UICC_FILE_STRUCTURE;