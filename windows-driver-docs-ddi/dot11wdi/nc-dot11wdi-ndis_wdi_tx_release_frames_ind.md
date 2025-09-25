# NDIS_WDI_TX_RELEASE_FRAMES_IND callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The NdisWdiTxReleaseFrameIndication callback function releases up to a specified number or aggregate cost of frames queued to a given peer-TID combination when transmission is paused. If the specified queues are not paused, none of the NET_BUFFER_LISTs are released.

This is a callback inside [NDIS_WDI_DATA_API](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_data_api).

## Parameters

### `NdisMiniportDataPathHandle` [in]

The NdisMiniportDataPathHandle passed to the IHV miniport in [MiniportWdiTalTxRxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_initialize).

### `PortId` [in]

The port ID. Must be a non-wildcard value.

### `PeerId` [in]

The peer ID. Must be a non-wildcard value.

### `ExTidBitmask` [in]

The Extended TID bitmask.

### `MaxNumFrames` [in]

Maximum frame count. *MaxNumFrames* is ignored if it is set to **WDI_TX_MAX_FRAME_COUNT_INVALID** (0xFF).

### `Credit` [in]

Credit. *Credit* is ignored if it is set to **WDI_TX_CREDIT_INVALID** (0xFFFF).

### `ppNBL` [out]

Pointer to a pointer to a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) chain of released frames.

## Remarks

if one of the specified queues is paused with **WDI_TX_PAUSE_REASON_PS**, the TAL/Target does not issue this indication until it has received a [MiniportWdiTxTalQueueInOrder](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tx_tal_queue_in_order) indication for that queue.

This indication is only allowed when **TargetPriorityQueueing** is false.

The TxMgr may return a list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) that exceed the limit of the number of frames or frame cost. This only happens if the frames are being requeued after being send completed with status of Postponed and with identical sequence number, which indicates they were originally transmitted as part of a single A-MSDU.

## See also

[MiniportWdiTxTalQueueInOrder](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tx_tal_queue_in_order)

[NDIS_WDI_DATA_API](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_data_api)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[WDI_PEER_ID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-peer-id)

[WDI_PORT_ID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-port-id)

[WDI_TXRX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_wdi_txrx_target_capabilities)

[WDI_TX_PAUSE_REASON](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ne-dot11wdi-_wdi_tx_pause_reason)