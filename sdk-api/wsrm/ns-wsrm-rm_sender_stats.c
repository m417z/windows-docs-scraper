typedef struct _RM_SENDER_STATS {
  ULONGLONG DataBytesSent;
  ULONGLONG TotalBytesSent;
  ULONGLONG NaksReceived;
  ULONGLONG NaksReceivedTooLate;
  ULONGLONG NumOutstandingNaks;
  ULONGLONG NumNaksAfterRData;
  ULONGLONG RepairPacketsSent;
  ULONGLONG BufferSpaceAvailable;
  ULONGLONG TrailingEdgeSeqId;
  ULONGLONG LeadingEdgeSeqId;
  ULONGLONG RateKBitsPerSecOverall;
  ULONGLONG RateKBitsPerSecLast;
  ULONGLONG TotalODataPacketsSent;
} RM_SENDER_STATS;