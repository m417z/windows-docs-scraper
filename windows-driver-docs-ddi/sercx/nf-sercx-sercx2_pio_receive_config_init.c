VOID SERCX2_PIO_RECEIVE_CONFIG_INIT(
  [out] SERCX2_PIO_RECEIVE_CONFIG                        *PioReceiveConfig,
  [in]  PFN_SERCX2_PIO_RECEIVE_READ_BUFFER               EvtSerCx2PioReceiveReadBuffer,
  [in]  PFN_SERCX2_PIO_RECEIVE_ENABLE_READY_NOTIFICATION EvtSerCx2PioReceiveEnableReadyNotification,
  [in]  PFN_SERCX2_PIO_RECEIVE_CANCEL_READY_NOTIFICATION EvtSerCx2PioReceiveCancelReadyNotification
);