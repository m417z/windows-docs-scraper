typedef struct _PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR {
  PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR_TYPE Type;
  ULONG                                     Flags;
  union {
    ULONG                                       CounterIndex;
    struct {
      ULONG Begin;
      ULONG End;
    } Range;
    PPHYSICAL_COUNTER_OVERFLOW_HANDLER          OverflowHandler;
    PHYSICAL_COUNTER_EVENT_BUFFER_CONFIGURATION EventBufferConfiguration;
    ULONG                                       IdentificationTag;
  } u;
} PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR, *PPHYSICAL_COUNTER_RESOURCE_DESCRIPTOR;