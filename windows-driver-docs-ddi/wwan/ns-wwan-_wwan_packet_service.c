typedef struct _WWAN_PACKET_SERVICE {
  ULONG                     uNwError;
  WWAN_PACKET_SERVICE_STATE PacketServiceState;
  ULONG                     AvailableDataClass;
  ULONG                     CurrentDataClass;
  WWAN_5G_FREQUENCY_RANGE   FrequencyRange;
  ULONG                     CurrentDataSubClass;
  WWAN_SINGLE_TAI           CurrentTai;
  ULONG                     Rel3GppVer;
} WWAN_PACKET_SERVICE, *PWWAN_PACKET_SERVICE;