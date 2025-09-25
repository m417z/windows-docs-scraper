typedef struct _NDIS_TIMER_CHARACTERISTICS {
  NDIS_OBJECT_HEADER   Header;
  ULONG                AllocationTag;
  PNDIS_TIMER_FUNCTION TimerFunction;
  PVOID                FunctionContext;
} NDIS_TIMER_CHARACTERISTICS, *PNDIS_TIMER_CHARACTERISTICS;