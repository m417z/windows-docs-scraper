NTSTATUS SerCx2CustomReceiveTransactionCreate(
  [in]  SERCX2CUSTOMRECEIVE                       CustomReceive,
  [in]  PSERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG CustomReceiveTransactionConfig,
  [in]  PWDF_OBJECT_ATTRIBUTES                    Attributes,
  [out] SERCX2CUSTOMRECEIVETRANSACTION            *CustomReceiveTransaction
);