typedef struct _SERCX2_CONFIG {
  ULONG                                            Size;
  PFN_SERCX2_FILEOPEN                              EvtSerCx2FileOpen;
  PFN_SERCX2_FILECLOSE                             EvtSerCx2FileClose;
  PFN_SERCX2_SET_WAIT_MASK                         EvtSerCx2SetWaitMask;
  PFN_SERCX2_PURGE_FIFOS                           EvtSerCx2PurgeFifos;
  PFN_SERCX2_CONTROL                               EvtSerCx2Control;
  PFN_SERCX2_APPLY_CONFIG                          EvtSerCx2ApplyConfig;
  PFN_SERCX2_SELECT_NEXT_RECEIVE_TRANSACTION_TYPE  EvtSerCx2SelectNextReceiveTransactionType;
  PFN_SERCX2_SELECT_NEXT_TRANSMIT_TRANSACTION_TYPE EvtSerCx2SelectNextTransmitTransactionType;
  PWDF_OBJECT_ATTRIBUTES                           RequestAttributes;
} SERCX2_CONFIG, *PSERCX2_CONFIG;