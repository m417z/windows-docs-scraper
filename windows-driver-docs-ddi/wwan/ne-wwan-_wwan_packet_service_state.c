typedef enum _WWAN_PACKET_SERVICE_STATE {
  WwanPacketServiceStateUnknown,
  WwanPacketServiceStateAttaching,
  WwanPacketServiceStateAttached,
  WwanPacketServiceStateDetaching,
  WwanPacketServiceStateDetached
} WWAN_PACKET_SERVICE_STATE, *PWWAN_PACKET_SERVICE_STATE;