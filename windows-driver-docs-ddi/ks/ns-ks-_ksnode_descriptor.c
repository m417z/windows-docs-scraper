typedef struct _KSNODE_DESCRIPTOR {
  const KSAUTOMATION_TABLE *AutomationTable;
  const GUID               *Type;
  const GUID               *Name;
  PVOID                    Alignment;
} KSNODE_DESCRIPTOR, *PKSNODE_DESCRIPTOR;