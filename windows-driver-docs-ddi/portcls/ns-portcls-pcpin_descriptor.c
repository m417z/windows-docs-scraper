typedef struct {
  ULONG                    MaxGlobalInstanceCount;
  ULONG                    MaxFilterInstanceCount;
  ULONG                    MinFilterInstanceCount;
  const PCAUTOMATION_TABLE *AutomationTable;
  KSPIN_DESCRIPTOR         KsPinDescriptor;
} PCPIN_DESCRIPTOR, *PPCPIN_DESCRIPTOR;