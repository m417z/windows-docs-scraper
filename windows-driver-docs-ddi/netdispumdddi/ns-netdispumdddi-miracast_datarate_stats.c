typedef struct {
  UINT64 EncoderBitRate;
  UINT64 CurrentMaxTxDataRate;
  UINT64 TransmittedFrameCount;
  UINT64 FailedFrameCount;
  UINT64 RetriedFrameCount;
  UINT64 MultipleRetryFrameCount;
} MIRACAST_DATARATE_STATS;