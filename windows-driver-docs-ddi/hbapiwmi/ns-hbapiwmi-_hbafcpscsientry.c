typedef struct _HBAFCPScsiEntry {
  HBAFCPID  FCPId;
  UCHAR     Luid[256];
  HBAScsiID ScsiId;
} HBAFCPScsiEntry, *PHBAFCPScsiEntry;