typedef enum _PKTMON_PACKET_TYPE {
  PktMonPayload_Unknown,
  PktMonPayload_Ethernet,
  PktMonPayload_WiFi,
  PktMonPayload_IP,
  PktMonPayload_HTTP,
  PktMonPayload_TCP,
  PktMonPayload_UDP,
  PktMonPayload_ARP,
  PktMonPayload_ICMP,
  PktMonPayload_ESP,
  PktMonPayload_AH,
  PktMonPayload_L4Payload
} PKTMON_PACKET_TYPE;