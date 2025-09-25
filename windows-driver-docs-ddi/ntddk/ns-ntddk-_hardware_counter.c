typedef struct _HARDWARE_COUNTER {
  HARDWARE_COUNTER_TYPE Type;
  ULONG                 Reserved;
  ULONG64               Index;
} HARDWARE_COUNTER, *PHARDWARE_COUNTER;