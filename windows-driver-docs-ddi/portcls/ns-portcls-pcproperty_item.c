typedef struct {
  const GUID            *Set;
  ULONG                 Id;
  ULONG                 Flags;
  PCPFNPROPERTY_HANDLER Handler;
} PCPROPERTY_ITEM, *PPCPROPERTY_ITEM;