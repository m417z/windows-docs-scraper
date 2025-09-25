typedef struct DOT11_MAC_FRAME_STATISTICS {
  ULONGLONG ullTransmittedFrameCount;
  ULONGLONG ullReceivedFrameCount;
  ULONGLONG ullTransmittedFailureFrameCount;
  ULONGLONG ullReceivedFailureFrameCount;
  ULONGLONG ullWEPExcludedCount;
  ULONGLONG ullTKIPLocalMICFailures;
  ULONGLONG ullTKIPReplays;
  ULONGLONG ullTKIPICVErrorCount;
  ULONGLONG ullCCMPReplays;
  ULONGLONG ullCCMPDecryptErrors;
  ULONGLONG ullWEPUndecryptableCount;
  ULONGLONG ullWEPICVErrorCount;
  ULONGLONG ullDecryptSuccessCount;
  ULONGLONG ullDecryptFailureCount;
} DOT11_MAC_FRAME_STATISTICS, *PDOT11_MAC_FRAME_STATISTICS;