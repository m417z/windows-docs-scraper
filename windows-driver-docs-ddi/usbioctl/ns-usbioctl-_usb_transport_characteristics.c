typedef struct _USB_TRANSPORT_CHARACTERISTICS {
  ULONG   Version;
  ULONG   TransportCharacteristicsFlags;
  ULONG64 CurrentRoundtripLatencyInMilliSeconds;
  ULONG64 MaxPotentialBandwidth;
} USB_TRANSPORT_CHARACTERISTICS, *PUSB_TRANSPORT_CHARACTERISTICS;