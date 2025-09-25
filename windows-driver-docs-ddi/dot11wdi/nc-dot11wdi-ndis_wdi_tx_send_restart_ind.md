# NDIS_WDI_TX_SEND_RESTART_IND callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The NdisWdiTxSendRestartIndication callback function resumes transmission on a given port to a given peer or peer-TID combination.

This is a callback inside [NDIS_WDI_DATA_API](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_data_api).

## Parameters

### `NdisMiniportDataPathHandle` [in]

The NdisMiniportDataPathHandle passed to the IHV miniport in [MiniportWdiTalTxRxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_initialize).

### `PortId` [in]

The port ID. Wildcards are accepted.

### `PeerId` [in]

The peer ID. Wildcards are accepted.

### `ExTidBitmask` [in]

The Extended TID bitmask. See *Remarks* section for more information.

### `TxRestartReason` [in]

TX restart reason bitmask, specified as [WDI_TX_PAUSE_REASON](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ne-dot11wdi-_wdi_tx_pause_reason) value(s). See *Remarks* section for more information.

## Remarks

In the *ExTidBitmask* parameter, the *i*th bit represents extended TID *i* (the least significant bit is bit 0) .

The [WDI_TX_PAUSE_REASON](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ne-dot11wdi-_wdi_tx_pause_reason) bitmask may contain a set of pause reasons. The pauses reasons are cumulative, so an [NdisWdiTxSendPauseIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_send_pause_ind) with a pause reason of **WDI_TX_PAUSE_REASON_CREDIT** followed by an *NdisWdiTxSendPauseIndication* with a pause reason of **WDI_TX_PAUSE_REASON_IHV1** requires an *NdisWdiTxSendRestartIndication* with a pause reason of (**WDI_TX_PAUSE_REASON_CREDIT** | **WDI_TX_PAUSE_REASON_IHV1**) for the set of queues to be unpaused.

If the pause reason is **WDI_TX_PAUSE_REASON_PS**, the TAL/target does not issue an *NdisWdiTxSendRestartIndication* to any of the affected queues until it has received an [MiniportWdiTxTalQueueInOrder](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tx_tal_queue_in_order) notification for that queue.
*NdisWdiTxSendRestartIndication* does not resume a queue if the queue has no remaining pause reason bits set after applying the restart reason bitmask.

If **TargetPriorityQueueing** is true, [WDI_PEER_ID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-peer-id) must be a wildcard. Only port or adapter restarts are allowed in this mode.

## See also

[NDIS_WDI_DATA_API](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_data_api)

[NdisWdiTxSendPauseIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_send_pause_ind)

[WDI_PEER_ID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-peer-id)

[WDI_PORT_ID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-port-id)

[WDI_TXRX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_wdi_txrx_target_capabilities)

[WDI_TX_PAUSE_REASON](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ne-dot11wdi-_wdi_tx_pause_reason)