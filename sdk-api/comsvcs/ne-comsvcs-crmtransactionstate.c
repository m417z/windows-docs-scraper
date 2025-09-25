typedef enum tagCrmTransactionState {
  TxState_Active = 0,
  TxState_Committed,
  TxState_Aborted,
  TxState_Indoubt
} CrmTransactionState;