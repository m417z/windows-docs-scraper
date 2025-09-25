typedef struct _PCPROPERTY_REQUEST {
  PUNKNOWN              MajorTarget;
  PUNKNOWN              MinorTarget;
  ULONG                 Node;
  const PCPROPERTY_ITEM *PropertyItem;
  ULONG                 Verb;
  ULONG                 InstanceSize;
  PVOID                 Instance;
  ULONG                 ValueSize;
  PVOID                 Value;
  PIRP                  Irp;
} PCPROPERTY_REQUEST, *PPCPROPERTY_REQUEST;