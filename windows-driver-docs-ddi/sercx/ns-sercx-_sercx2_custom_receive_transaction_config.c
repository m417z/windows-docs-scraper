typedef struct _SERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG {
  ULONG                                                              Size;
  PFN_SERCX2_CUSTOM_RECEIVE_TRANSACTION_INITIALIZE                   EvtSerCx2CustomReceiveTransactionInitialize;
  PFN_SERCX2_CUSTOM_RECEIVE_TRANSACTION_START                        EvtSerCx2CustomReceiveTransactionStart;
  PFN_SERCX2_CUSTOM_RECEIVE_TRANSACTION_CLEANUP                      EvtSerCx2CustomReceiveTransactionCleanup;
  PFN_SERCX2_CUSTOM_RECEIVE_TRANSACTION_ENABLE_NEW_DATA_NOTIFICATION EvtSerCx2CustomReceiveTransactionEnableNewDataNotification;
  PFN_SERCX2_CUSTOM_RECEIVE_TRANSACTION_QUERY_PROGRESS               EvtSerCx2CustomReceiveTransactionQueryProgress;
} SERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG, *PSERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG;