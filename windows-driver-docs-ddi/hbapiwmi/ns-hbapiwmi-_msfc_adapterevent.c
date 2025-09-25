typedef struct _MSFC_AdapterEvent {
  ULONG EventType;
  UCHAR PortWWN[8];
} MSFC_AdapterEvent, *PMSFC_AdapterEvent;