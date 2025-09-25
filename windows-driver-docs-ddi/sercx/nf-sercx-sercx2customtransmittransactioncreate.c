NTSTATUS SerCx2CustomTransmitTransactionCreate(
  [in]  SERCX2CUSTOMTRANSMIT                       CustomTransmit,
  [in]  PSERCX2_CUSTOM_TRANSMIT_TRANSACTION_CONFIG CustomTransmitTransactionConfig,
  [in]  PWDF_OBJECT_ATTRIBUTES                     Attributes,
  [out] SERCX2CUSTOMTRANSMITTRANSACTION            *CustomTransmitTransaction
);