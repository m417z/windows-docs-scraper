typedef struct CF_OPERATION_INFO {
  ULONG                    StructSize;
  CF_OPERATION_TYPE        Type;
  CF_CONNECTION_KEY        ConnectionKey;
  CF_TRANSFER_KEY          TransferKey;
  const CORRELATION_VECTOR *CorrelationVector;
  const CF_SYNC_STATUS     *SyncStatus;
  CF_REQUEST_KEY           RequestKey;
} CF_OPERATION_INFO;