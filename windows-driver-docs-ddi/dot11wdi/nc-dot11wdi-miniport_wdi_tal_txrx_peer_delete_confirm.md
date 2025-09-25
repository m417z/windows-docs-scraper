# MINIPORT_WDI_TAL_TXRX_PEER_DELETE_CONFIRM callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The
MiniportWdiTalTxRxPeerDeleteConfirm handler function is invoked after the completion of a [PeerDeleteIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_peer_delete_ind) call which did not return success. This is called after a successful [MiniportWdiTxAbort](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tx_abort) (or [TxAbortConfirm](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_abort_confirm)) and after all outstanding TX frames for the peer are completed. After this call, the mapping between the peer Id and MAC address is no longer valid and the peer Id and MAC address may be used for future [PeerCreateIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_peer_create_ind) calls.

This is a WDI miniport handler inside [NDIS_MINIPORT_WDI_DATA_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_wdi_data_handlers).

**Note** You must declare the function by using the **MINIPORT_WDI_TAL_TXRX_PEER_DELETE_CONFIRM** type. For more
information, see the following Examples section.

## Parameters

### `MiniportTalTxRxContext` [in]

TAL device handle returned by the IHV miniport in [MiniportWdiTalTxRxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_initialize).

### `PortId` [in]

Port ID associated with the peer.

### `PeerId` [in]

Peer ID for the peer.

## See also

[MiniportWdiTxAbort](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tx_abort)

[NDIS_MINIPORT_WDI_DATA_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_wdi_data_handlers)

[PeerCreateIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_peer_create_ind)

[PeerDeleteIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_peer_delete_ind)

[TAL_TXRX_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/network/tal-txrx-handle)

[TxAbortConfirm](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_abort_confirm)

[WDI general datapath interfaces](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-general-datapath-interfaces)

[WDI_PEER_ID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-peer-id)

[WDI_PORT_ID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-port-id)