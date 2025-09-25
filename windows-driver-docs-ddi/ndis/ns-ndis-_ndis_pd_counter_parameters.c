typedef struct _NDIS_PD_COUNTER_PARAMETERS {
  NDIS_OBJECT_HEADER   Header;
  ULONG                Flags;
  PCWSTR               CounterName;
  NDIS_PD_COUNTER_TYPE Type;
} NDIS_PD_COUNTER_PARAMETERS;