typedef struct _TXFS_GET_METADATA_INFO_OUT {
  struct {
    LONGLONG LowPart;
    LONGLONG HighPart;
  } TxfFileId;
  GUID      LockingTransaction;
  DWORDLONG LastLsn;
  DWORD     TransactionState;
} TXFS_GET_METADATA_INFO_OUT, *PTXFS_GET_METADATA_INFO_OUT;