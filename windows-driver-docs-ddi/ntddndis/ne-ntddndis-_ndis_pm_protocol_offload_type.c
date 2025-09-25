typedef enum _NDIS_PM_PROTOCOL_OFFLOAD_TYPE {
  NdisPMProtocolOffloadIdUnspecified,
  NdisPMProtocolOffloadIdIPv4ARP,
  NdisPMProtocolOffloadIdIPv6NS,
  NdisPMProtocolOffload80211RSNRekey,
  NdisPMProtocolOffload80211RSNRekeyV2,
  NdisPMProtocolOffloadIdMaximum
} NDIS_PM_PROTOCOL_OFFLOAD_TYPE, *PNDIS_PM_PROTOCOL_OFFLOAD_TYPE;