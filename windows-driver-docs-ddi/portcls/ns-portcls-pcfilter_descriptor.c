typedef struct {
  ULONG                         Version;
  const PCAUTOMATION_TABLE      *AutomationTable;
  ULONG                         PinSize;
  ULONG                         PinCount;
  const PCPIN_DESCRIPTOR        *Pins;
  ULONG                         NodeSize;
  ULONG                         NodeCount;
  const PCNODE_DESCRIPTOR       *Nodes;
  ULONG                         ConnectionCount;
  const PCCONNECTION_DESCRIPTOR *Connections;
  ULONG                         CategoryCount;
  const GUID                    *Categories;
} PCFILTER_DESCRIPTOR, *PPCFILTER_DESCRIPTOR;