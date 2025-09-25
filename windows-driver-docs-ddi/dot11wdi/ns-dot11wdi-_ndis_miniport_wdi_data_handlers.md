# _NDIS_MINIPORT_WDI_DATA_HANDLERS structure

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The NDIS_MINIPORT_WDI_DATA_HANDLERS structure specifies the entry points for the IHV miniport datapath handlers.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_MINIPORT_WDI_DATA_HANDLERS structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_MINIPORT_WDI_DATA_HANDLERS.

To indicate the version of the NDIS_MINIPORT_WDI_DATA_HANDLERS structure, set the
**Revision** member to the following value:

#### NDIS_OBJECT_TYPE_MINIPORT_WDI_DATA_HANDLERS_REVISION_1

Set the
**Size** member to NDIS_SIZEOF_MINIPORT_WDI_DATA_HANDLERS_REVISION_1.

### `TxAbortHandler`

The entry point of the [MiniportWdiTxAbort](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tx_abort) handler function.

### `TxTargetDescInitHandler`

The entry point of the [MiniportWdiTxTargetDescInit](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tx_target_desc_init) handler function.

### `TxTargetDescDeInitHandler`

The entry point of the [MiniportWdiTxTargetDescDeInit](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tx_target_desc_deinit) handler function.

### `TxDataSendHandler`

The entry point of the [MiniportWdiTxDataSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tx_data_send) handler function.

### `TxTalSendHandler`

The entry point of the [MiniportWdiTxTalSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tx_tal_send) handler function.

### `TxTalSendCompleteHandler`

The entry point of the [MiniportWdiTxTalSendComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tx_tal_send_complete) handler function.

### `TxTalQueueInOrderHandler`

The entry point of the [MiniportWdiTxTalQueueInOrder](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tx_tal_queue_in_order) handler function.

### `TxPeerBacklogHandler`

The entry point of the [MiniportWdiTxPeerBacklog](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tx_peer_backlog) handler function.

### `RxStopHandler`

The entry point of the [MiniportWdiRxStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_rx_stop) handler function.

### `RxFlushHandler`

The entry point of the [MiniportWdiRxFlush](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_rx_flush) handler function.

### `RxRestartHandler`

The entry point of the [MiniportWdiRxRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_rx_restart) handler function.

### `RxGetMpdusHandler`

The entry point of the [MiniportWdiRxGetMpdus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_rx_get_mpdus) handler function.

### `RxReturnFramesHandler`

The entry point of the [MiniportWdiRxReturnFrames](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_rx_return_frames) handler function.

### `RxResumeHandler`

The entry point of the [MiniportWdiRxResume](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_rx_resume) handler function.

### `RxThrottleHandler`

The entry point of the [MiniportWdiRxThrottle](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_rx_throttle) handler function.

### `RxPpduRssiHandler`

The entry point of the [MiniportWdiRxPpduRssi](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_rx_ppdu_rssi) handler function.

### `TalTxRxStartHandler`

The entry point of the [MiniportWdiTalTxRxStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_start) handler function.

### `TalTxRxStopHandler`

The entry point of the [MiniportWdiTalTxRxStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_stop) handler function.

### `TalTxRxAddPortHandler`

The entry point of the [MiniportWdiTalTxRxAddPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_add_port) handler function.

### `TalTxRxDeletePortHandler`

The entry point of the [MiniportWdiTalTxRxDeletePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_delete_port) handler function.

### `TalTxRxSetPortOpModeHandler`

The entry point of the [MiniportWdiTalTxRxSetPortOpMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_set_port_opmode) handler function.

### `TalTxRxResetPortHandler`

The entry point of the [MiniportWdiTalTxRxResetPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_reset_port) handler function.

### `TalTxRxPeerConfigHandler`

The entry point of the [MiniportWdiTalTxRxPeerConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_peer_config) handler function.

### `TalTxRxPeerDeleteConfirmHandler`

The entry point of the [MiniportWdiTalTxRxPeerDeleteConfirm](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_peer_delete_confirm) handler function.

### `TxSuspectFrameAbortHandler`

The entry point of the [MiniportWdiTxSuspectFrameAbort](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tx_suspect_frame_list_abort) handler function.