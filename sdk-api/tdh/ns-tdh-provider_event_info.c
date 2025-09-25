typedef struct _PROVIDER_EVENT_INFO {
  ULONG            NumberOfEvents;
  ULONG            Reserved;
  EVENT_DESCRIPTOR EventDescriptorsArray[ANYSIZE_ARRAY];
} PROVIDER_EVENT_INFO;