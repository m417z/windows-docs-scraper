typedef struct _SERCX2_PIO_TRANSMIT_CONFIG {
  ULONG                                             Size;
  PFN_SERCX2_PIO_TRANSMIT_INITIALIZE_TRANSACTION    EvtSerCx2PioTransmitInitializeTransaction;
  PFN_SERCX2_PIO_TRANSMIT_CLEANUP_TRANSACTION       EvtSerCx2PioTransmitCleanupTransaction;
  PFN_SERCX2_PIO_TRANSMIT_WRITE_BUFFER              EvtSerCx2PioTransmitWriteBuffer;
  PFN_SERCX2_PIO_TRANSMIT_ENABLE_READY_NOTIFICATION EvtSerCx2PioTransmitEnableReadyNotification;
  PFN_SERCX2_PIO_TRANSMIT_CANCEL_READY_NOTIFICATION EvtSerCx2PioTransmitCancelReadyNotification;
  PFN_SERCX2_PIO_TRANSMIT_DRAIN_FIFO                EvtSerCx2PioTransmitDrainFifo;
  PFN_SERCX2_PIO_TRANSMIT_CANCEL_DRAIN_FIFO         EvtSerCx2PioTransmitCancelDrainFifo;
  PFN_SERCX2_PIO_TRANSMIT_PURGE_FIFO                EvtSerCx2PioTransmitPurgeFifo;
} SERCX2_PIO_TRANSMIT_CONFIG, *PSERCX2_PIO_TRANSMIT_CONFIG;