typedef struct {
  ULONG                    Flags;
  const PCAUTOMATION_TABLE *AutomationTable;
  const GUID               *Type;
  const GUID               *Name;
} PCNODE_DESCRIPTOR, *PPCNODE_DESCRIPTOR;