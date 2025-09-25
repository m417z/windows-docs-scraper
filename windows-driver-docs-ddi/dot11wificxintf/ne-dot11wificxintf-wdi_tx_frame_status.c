typedef enum _WDI_TX_FRAME_STATUS {
  WDI_TxFrameStatus_Ok,
  WDI_TxFrameStatus_Discard,
  WDI_TxFrameStatus_NoAck,
  WDI_TxFrameStatus_TransferCancelled,
  WDI_TxFrameStatus_SendCancelled,
  WDI_TxFrameStatus_SendPostponed,
  WDI_TxFrameStatus_TransferFailed
} WDI_TX_FRAME_STATUS;