typedef struct _MSFC_HBAPortStatistics {
  LONGLONG SecondsSinceLastReset;
  LONGLONG TxFrames;
  LONGLONG TxWords;
  LONGLONG RxFrames;
  LONGLONG RxWords;
  LONGLONG LIPCount;
  LONGLONG NOSCount;
  LONGLONG ErrorFrames;
  LONGLONG DumpedFrames;
  LONGLONG LinkFailureCount;
  LONGLONG LossOfSyncCount;
  LONGLONG LossOfSignalCount;
  LONGLONG PrimitiveSeqProtocolErrCount;
  LONGLONG InvalidTxWordCount;
  LONGLONG InvalidCRCCount;
} MSFC_HBAPortStatistics, *PMSFC_HBAPortStatistics;