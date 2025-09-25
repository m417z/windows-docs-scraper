typedef struct _MSFC_EventBuffer {
  ULONG EventType;
  ULONG EventInfo[4];
} MSFC_EventBuffer, *PMSFC_EventBuffer;