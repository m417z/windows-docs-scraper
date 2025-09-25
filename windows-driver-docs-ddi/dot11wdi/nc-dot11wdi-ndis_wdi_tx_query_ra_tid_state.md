# NDIS_WDI_TX_QUERY_RA_TID_STATE callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The NdisWdiTxQueryRATIDState callback function is used by the TxEngine to query the state of a RA/TID or Port queue.

This is a callback inside [NDIS_WDI_DATA_API](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_data_api).

## Parameters

### `NdisMiniportDataPathHandle` [in]

The NdisMiniportDataPathHandle passed to the IHV miniport in [MiniportWdiTalTxRxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_initialize).

### `PortId` [in]

The port ID.

### `PeerId` [in]

The peer ID.

### `ExTid` [in]

The Extended Traffic ID (TID)

### `pWifiStatus` [out]

Indicates the result of the query operation. See the *Remarks* section for more information.

### `pQueueLength` [out]

The number of backlogged frames in the specified RA/TID or Port queue.

## Remarks

The TxMgr returns a success status if the port and peer are valid. Otherwise, it returns an error status. In the case of a success status, the *QueueLength* is set to the number of backlogged frames in the specified RA/TID or Port queue.

If **TargetPriorityQueueing** is true, [WDI_PEER_ID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-peer-id) must be set to the wildcard peer value.

## See also

[NDIS_WDI_DATA_API](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_data_api)

[WDI_EXTENDED_TID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-extended-tid)

[WDI_PEER_ID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-peer-id)

[WDI_PORT_ID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-port-id)

[WDI_TXRX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_wdi_txrx_target_capabilities)