typedef struct _TXN_PARAMETER_BLOCK {
  USHORT Length;
  USHORT TxFsContext;
  PVOID  TransactionObject;
} TXN_PARAMETER_BLOCK, *PTXN_PARAMETER_BLOCK;