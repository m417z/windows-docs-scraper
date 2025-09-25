VOID SERCX2_PIO_TRANSMIT_CONFIG_INIT(
  [out] SERCX2_PIO_TRANSMIT_CONFIG                        *PioTransmitConfig,
  [in]  PFN_SERCX2_PIO_TRANSMIT_WRITE_BUFFER              EvtSerCx2PioTransmitWriteBuffer,
  [in]  PFN_SERCX2_PIO_TRANSMIT_ENABLE_READY_NOTIFICATION EvtSerCx2PioTransmitEnableReadyNotification,
  [in]  PFN_SERCX2_PIO_TRANSMIT_CANCEL_READY_NOTIFICATION EvtSerCx2PioTransmitCancelReadyNotification
);