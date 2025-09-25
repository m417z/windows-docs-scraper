typedef struct _MSFC_PortEvent {
  ULONG EventType;
  ULONG FabricPortId;
  UCHAR PortWWN[8];
} MSFC_PortEvent, *PMSFC_PortEvent;