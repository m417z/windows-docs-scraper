typedef struct _WHEA_THROTTLE_PCIE_ADD_EVENT {
  WHEA_EVENT_LOG_ENTRY WheaEventLogEntry;
  WHEA_PCIE_ADDRESS    Address;
  UINT32               Mask;
  BOOLEAN              Updated;
  NTSTATUS             Status;
} WHEA_THROTTLE_PCIE_ADD_EVENT, *PWHEA_THROTTLE_PCIE_ADD_EVENT;