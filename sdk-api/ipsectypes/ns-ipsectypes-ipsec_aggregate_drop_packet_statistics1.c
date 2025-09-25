typedef struct IPSEC_AGGREGATE_DROP_PACKET_STATISTICS1_ {
  UINT32 invalidSpisOnInbound;
  UINT32 decryptionFailuresOnInbound;
  UINT32 authenticationFailuresOnInbound;
  UINT32 udpEspValidationFailuresOnInbound;
  UINT32 replayCheckFailuresOnInbound;
  UINT32 invalidClearTextInbound;
  UINT32 saNotInitializedOnInbound;
  UINT32 receiveOverIncorrectSaInbound;
  UINT32 secureReceivesNotMatchingFilters;
  UINT32 totalDropPacketsInbound;
} IPSEC_AGGREGATE_DROP_PACKET_STATISTICS1;