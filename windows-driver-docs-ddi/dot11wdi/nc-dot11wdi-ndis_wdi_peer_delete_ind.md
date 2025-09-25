# NDIS_WDI_PEER_DELETE_IND callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The
NdisWdiPeerDeleteIndication callback function initiates the removal of the association of between a peer ID and a peer MAC address. Once this indication is processed, the peer ID can no longer be used in subsequent Rx indications and the IHV may not inject any Tx frames for this peer.

This is a callback inside [NDIS_WDI_DATA_API](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_data_api).

## Parameters

### `NdisMiniportDataPathHandle` [in]

The NdisMiniportDataPathHandle passed to IHV miniport in [MiniportWdiTalTxRxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_initialize).

### `PortId` [in]

The port ID.

### `PeerId` [in]

The peer ID.

### `pWifiStatus` [out]

Indicates whether the peer deletion completed synchronously (if status is set to **NDIS_STATUS_SUCCESS**), or whether WDI will issue a [MiniportWdiTalTxRxPeerDeleteConfirm](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_peer_delete_confirm) when peer deletion completes.

## Remarks

In PeerQueueing mode, the TxMgr issues a TxAbort for the peer. If the [MiniportWdiTxAbort](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tx_abort) completes synchronously and there are no outstanding TX frames for that peer, WDI_STATUS is set to NDIS_STATUS_SUCCESS and the peer deletion is complete (see [MiniportWdiTalTxRxPeerDeleteConfirm](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_peer_delete_confirm) for the description of a peer delete completion). Otherwise, WDI issues a *MiniportWdiTalTxRxPeerDeleteConfirm* when the TxAbort is completed and there are no outstanding frames for this peer.

## See also

[MiniportWdiTalTxRxPeerDeleteConfirm](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_peer_delete_confirm)

[MiniportWdiTxAbort](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tx_abort)

[NDIS_MINIPORT_WDI_DATA_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_wdi_data_handlers)

[NDIS_WDI_DATA_API](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_data_api)

[WDI general datapath interfaces](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-general-datapath-interfaces)

[WDI_PEER_ID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-peer-id)

[WDI_PORT_ID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-port-id)