typedef struct _MSFC_TargetEvent {
  ULONG EventType;
  UCHAR PortWWN[8];
  UCHAR DiscoveredPortWWN[8];
} MSFC_TargetEvent, *PMSFC_TargetEvent;