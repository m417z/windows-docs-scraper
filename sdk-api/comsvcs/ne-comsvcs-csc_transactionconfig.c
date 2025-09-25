typedef enum tagCSC_TransactionConfig {
  CSC_NoTransaction = 0,
  CSC_IfContainerIsTransactional,
  CSC_CreateTransactionIfNecessary,
  CSC_NewTransaction
} CSC_TransactionConfig;