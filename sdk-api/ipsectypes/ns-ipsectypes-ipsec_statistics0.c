typedef struct IPSEC_STATISTICS0_ {
  IPSEC_AGGREGATE_SA_STATISTICS0          aggregateSaStatistics;
  IPSEC_ESP_DROP_PACKET_STATISTICS0       espDropPacketStatistics;
  IPSEC_AH_DROP_PACKET_STATISTICS0        ahDropPacketStatistics;
  IPSEC_AGGREGATE_DROP_PACKET_STATISTICS0 aggregateDropPacketStatistics;
  IPSEC_TRAFFIC_STATISTICS0               inboundTrafficStatistics;
  IPSEC_TRAFFIC_STATISTICS0               outboundTrafficStatistics;
} IPSEC_STATISTICS0;