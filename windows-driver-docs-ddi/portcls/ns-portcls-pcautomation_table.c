typedef struct {
  ULONG                 PropertyItemSize;
  ULONG                 PropertyCount;
  const PCPROPERTY_ITEM *Properties;
  ULONG                 MethodItemSize;
  ULONG                 MethodCount;
  const PCMETHOD_ITEM   *Methods;
  ULONG                 EventItemSize;
  ULONG                 EventCount;
  const PCEVENT_ITEM    *Events;
  ULONG                 Reserved;
} PCAUTOMATION_TABLE, *PPCAUTOMATION_TABLE;