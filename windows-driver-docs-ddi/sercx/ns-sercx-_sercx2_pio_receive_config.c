typedef struct _SERCX2_PIO_RECEIVE_CONFIG {
  ULONG                                            Size;
  PFN_SERCX2_PIO_RECEIVE_INITIALIZE_TRANSACTION    EvtSerCx2PioReceiveInitializeTransaction;
  PFN_SERCX2_PIO_RECEIVE_CLEANUP_TRANSACTION       EvtSerCx2PioReceiveCleanupTransaction;
  PFN_SERCX2_PIO_RECEIVE_READ_BUFFER               EvtSerCx2PioReceiveReadBuffer;
  PFN_SERCX2_PIO_RECEIVE_ENABLE_READY_NOTIFICATION EvtSerCx2PioReceiveEnableReadyNotification;
  PFN_SERCX2_PIO_RECEIVE_CANCEL_READY_NOTIFICATION EvtSerCx2PioReceiveCancelReadyNotification;
} SERCX2_PIO_RECEIVE_CONFIG, *PSERCX2_PIO_RECEIVE_CONFIG;