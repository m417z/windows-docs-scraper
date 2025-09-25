VOID SERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG_INIT(
  [out]          SERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG                           *Config,
  [in]           PFN_SERCX2_CUSTOM_RECEIVE_TRANSACTION_START                        EvtSerCx2CustomReceiveTransactionStart,
  [in, optional] PFN_SERCX2_CUSTOM_RECEIVE_TRANSACTION_ENABLE_NEW_DATA_NOTIFICATION EvtSerCx2CustomReceiveTransactionEnableNewDataNotification,
  [in]           PFN_SERCX2_CUSTOM_RECEIVE_TRANSACTION_QUERY_PROGRESS               EvtSerCx2CustomReceiveTransactionQueryProgress
);