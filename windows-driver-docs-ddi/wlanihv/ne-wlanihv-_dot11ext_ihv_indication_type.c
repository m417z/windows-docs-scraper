typedef enum _DOT11EXT_IHV_INDICATION_TYPE {
  IndicationTypeNicSpecificNotification  = 0,
  IndicationTypePmkidCandidateList       = 1,
  IndicationTypeTkipMicFailure           = 2,
  IndicationTypePhyStateChange           = 3,
  IndicationTypeLinkQuality              = 4
} DOT11EXT_IHV_INDICATION_TYPE, *PDOT11EXT_IHV_INDICATION_TYPE;