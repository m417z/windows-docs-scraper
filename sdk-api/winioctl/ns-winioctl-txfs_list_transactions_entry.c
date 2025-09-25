typedef struct _TXFS_LIST_TRANSACTIONS_ENTRY {
  GUID     TransactionId;
  DWORD    TransactionState;
  DWORD    Reserved1;
  DWORD    Reserved2;
  LONGLONG Reserved3;
} TXFS_LIST_TRANSACTIONS_ENTRY, *PTXFS_LIST_TRANSACTIONS_ENTRY;