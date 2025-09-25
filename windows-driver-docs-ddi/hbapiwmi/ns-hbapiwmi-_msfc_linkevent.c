typedef struct _MSFC_LinkEvent {
  ULONG EventType;
  UCHAR AdapterWWN[8];
  ULONG RLIRBufferSize;
  UCHAR RLIRBuffer[1];
} MSFC_LinkEvent, *PMSFC_LinkEvent;