typedef struct tagRECO_ATTRS {
  DWORD dwRecoCapabilityFlags;
  WCHAR awcVendorName[32];
  WCHAR awcFriendlyName[64];
  WORD  awLanguageId[64];
} RECO_ATTRS;