typedef struct {
  const GUID          *Set;
  ULONG               Id;
  ULONG               Flags;
  PCPFNMETHOD_HANDLER Handler;
} PCMETHOD_ITEM, *PPCMETHOD_ITEM;