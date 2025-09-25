typedef struct _HBAFCPBindingEntry {
  ULONG     Type;
  HBAFCPID  FCPId;
  HBAScsiID ScsiId;
} HBAFCPBindingEntry, *PHBAFCPBindingEntry;