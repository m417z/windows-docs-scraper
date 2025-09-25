typedef struct _HBAFCPBindingEntry2 {
  ULONG     Type;
  HBAFCPID  FCPId;
  UCHAR     Luid[256];
  HBAScsiID ScsiId;
} HBAFCPBindingEntry2, *PHBAFCPBindingEntry2;