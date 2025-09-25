typedef struct _GetEventBuffer_OUT {
  ULONG            HBAStatus;
  ULONG            EventCount;
  MSFC_EventBuffer Events[1];
} GetEventBuffer_OUT, *PGetEventBuffer_OUT;