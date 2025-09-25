typedef struct _DOT11_PEER_STATISTICS {
  ULONGLONG ullDecryptSuccessCount;
  ULONGLONG ullDecryptFailureCount;
  ULONGLONG ullTxPacketSuccessCount;
  ULONGLONG ullTxPacketFailureCount;
  ULONGLONG ullRxPacketSuccessCount;
  ULONGLONG ullRxPacketFailureCount;
} DOT11_PEER_STATISTICS, *PDOT11_PEER_STATISTICS;