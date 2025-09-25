typedef struct HBA_PortStatistics {
  HBA_INT64 SecondsSinceLastReset;
  HBA_INT64 TxFrames;
  HBA_INT64 TxWords;
  HBA_INT64 RxFrames;
  HBA_INT64 RxWords;
  HBA_INT64 LIPCount;
  HBA_INT64 NOSCount;
  HBA_INT64 ErrorFrames;
  HBA_INT64 DumpedFrames;
  HBA_INT64 LinkFailureCount;
  HBA_INT64 LossOfSyncCount;
  HBA_INT64 LossOfSignalCount;
  HBA_INT64 PrimitiveSeqProtocolErrCount;
  HBA_INT64 InvalidTxWordCount;
  HBA_INT64 InvalidCRCCount;
} HBA_PORTSTATISTICS, *PHBA_PORTSTATISTICS;