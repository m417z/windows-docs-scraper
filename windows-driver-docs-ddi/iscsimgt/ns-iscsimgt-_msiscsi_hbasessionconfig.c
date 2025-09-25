typedef struct _MSiSCSI_HBASessionConfig {
  BOOLEAN InitialR2T;
  BOOLEAN ImmediateData;
  ULONG   MaxRecvDataSegmentLength;
  ULONG   MaxBurstLength;
  ULONG   FirstBurstLength;
  ULONG   MaxOutstandingR2T;
} MSiSCSI_HBASessionConfig, *PMSiSCSI_HBASessionConfig;