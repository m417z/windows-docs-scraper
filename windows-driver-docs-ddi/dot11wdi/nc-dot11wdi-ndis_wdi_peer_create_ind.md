# NDIS_WDI_PEER_CREATE_IND callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The NdisWdiPeerCreateIndication callback function specifies a peer ID to associate with a peer MAC address.

This is a callback inside [NDIS_WDI_DATA_API](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_data_api).

## Parameters

### `NdisMiniportDataPathHandle` [in]

The NdisMiniportDataPathHandle passed to IHV miniport in [MiniportWdiTalTxRxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_initialize).

### `PortId` [in]

The port ID.

### `PeerId` [in]

The peer ID. This is used to identify the peer in subsequent commands and indications.

### `PeerAddr` [in]

The peer MAC address.

## Remarks

This must be received and processed prior to exchanging frames with the peer.

A port operating in AP or Wi-Fi Direct GO mode may simultaneously have more than one peer (clients). When a port is operating in AP or Wi-Fi Direct GO mode, the IHV miniport creates a 'peer' for group addressed traffic (by passing a broadcast MAC address). All multicast and broadcast traffic for this port is associated with this peer. In port queuing mode, the creation of the group peer by the IHV miniport is not required as Tx frame classification does not occur in this mode.

A port operating in any mode may create a group peer.

To facilitate TDLS implementation in the IHV component, a port operating in STA or Wi-Fi Direct client mode may simultaneously have more than one peer. If a TX frame's destination MAC address matches is associated with a non-AP/GO peer ID, the TxMgr queues the frame with a TID queue associated with that non-AP/GO peer (if WDI is operating in PeerTID queuing mode).

In peer queuing mode, a peer is created with all TIDs paused with **WDI_TX_PAUSE_REASON_PEER_CREATE**.

## See also

[NDIS_WDI_DATA_API](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_data_api)

[WDI general datapath interfaces](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-general-datapath-interfaces)

[WDI_MAC_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_wdi_mac_address)

[WDI_PEER_ID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-peer-id)

[WDI_PORT_ID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-port-id)