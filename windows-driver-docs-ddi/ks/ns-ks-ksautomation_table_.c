typedef struct KSAUTOMATION_TABLE_ {
  ULONG                PropertySetsCount;
  ULONG                PropertyItemSize;
  const KSPROPERTY_SET *PropertySets;
  ULONG                MethodSetsCount;
  ULONG                MethodItemSize;
  const KSMETHOD_SET   *MethodSets;
  ULONG                EventSetsCount;
  ULONG                EventItemSize;
  const KSEVENT_SET    *EventSets;
  PVOID                Alignment;
} KSAUTOMATION_TABLE, *PKSAUTOMATION_TABLE;