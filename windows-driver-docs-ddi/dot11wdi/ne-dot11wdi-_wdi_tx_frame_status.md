# _WDI_TX_FRAME_STATUS enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The WDI_TX_FRAME_STATUS enumeration defines the TX frame status values.

## Constants

### `WDI_TxFrameStatus_Ok`

Frame transmitted without errors.

### `WDI_TxFrameStatus_Discard`

The frame was discarded to make room for higher priority frames.

### `WDI_TxFrameStatus_NoAck`

Transmission failed after exhausting the maximum number of retries.

### `WDI_TxFrameStatus_TransferCancelled`

TX stop requested.

### `WDI_TxFrameStatus_SendCancelled`

TX stop requested.

### `WDI_TxFrameStatus_SendPostponed`

The frame could not be transmitted at this time (for example, the peer is in PS). The frame should be transferred at a suitable time, when the corresponding TX queue is unpaused. This status is not allowed for targets that have **TargetPriorityQueueing** set to TRUE.

### `WDI_TxFrameStatus_TransferFailed`

The transfer failed.

## See also

[WDI_TXRX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_wdi_txrx_target_capabilities)