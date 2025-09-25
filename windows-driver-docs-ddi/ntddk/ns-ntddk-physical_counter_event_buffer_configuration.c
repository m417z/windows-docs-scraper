typedef struct _PHYSICAL_COUNTER_EVENT_BUFFER_CONFIGURATION {
  PPHYSICAL_COUNTER_EVENT_BUFFER_OVERFLOW_HANDLER OverflowHandler;
  ULONG                                           CustomEventBufferEntrySize;
  ULONG                                           EventThreshold;
} PHYSICAL_COUNTER_EVENT_BUFFER_CONFIGURATION, *PPHYSICAL_COUNTER_EVENT_BUFFER_CONFIGURATION;