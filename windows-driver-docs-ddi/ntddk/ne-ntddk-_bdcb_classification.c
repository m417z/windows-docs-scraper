typedef enum _BDCB_CLASSIFICATION {
  BdCbClassificationUnknownImage,
  BdCbClassificationKnownGoodImage,
  BdCbClassificationKnownBadImage,
  BdCbClassificationKnownBadImageBootCritical,
  BdCbClassificationEnd
} BDCB_CLASSIFICATION, *PBDCB_CLASSIFICATION;