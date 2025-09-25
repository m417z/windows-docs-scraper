typedef struct IPSEC_ESP_DROP_PACKET_STATISTICS0_ {
  UINT32 invalidSpisOnInbound;
  UINT32 decryptionFailuresOnInbound;
  UINT32 authenticationFailuresOnInbound;
  UINT32 replayCheckFailuresOnInbound;
  UINT32 saNotInitializedOnInbound;
} IPSEC_ESP_DROP_PACKET_STATISTICS0;