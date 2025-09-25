typedef struct _MSiSCSI_NICPerformance {
  ULONG BytesTransmitted;
  ULONG BytesReceived;
  ULONG PDUTransmitted;
  ULONG PDUReceived;
} MSiSCSI_NICPerformance, *PMSiSCSI_NICPerformance;