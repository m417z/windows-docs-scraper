typedef struct _PCMETHOD_REQUEST {
  PUNKNOWN            MajorTarget;
  PUNKNOWN            MinorTarget;
  ULONG               Node;
  const PCMETHOD_ITEM *MethodItem;
  ULONG               Verb;
} PCMETHOD_REQUEST, *PPCMETHOD_REQUEST;