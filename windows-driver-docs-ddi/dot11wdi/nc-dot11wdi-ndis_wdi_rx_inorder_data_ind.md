# NDIS_WDI_RX_INORDER_DATA_IND callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The
NdisWdiRxInorderDataIndication callback function informs the RxMgr that a list of specified RX frames in the correct order are present.

This is a callback inside [NDIS_WDI_DATA_API](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_data_api).

## Parameters

### `NdisMiniportDataPathHandle` [in]

The NdisMiniportDataPathHandle passed to the IHV miniport in [MiniportWdiTalTxRxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_initialize).

### `IndicationLevel` [in]

A [WDI_RX_INDICATION_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ne-dot11wdi-_wdi_rx_indication_level) enumeration value that specifies the RX indication level.

### `PeerId` [in]

The peer ID.

### `ExTid` [in]

The extended TID.

### `pRxThrottleParams` [in]

Pointer to a [NDIS_RECEIVE_THROTTLE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_receive_throttle_parameters) structure.

### `pWifiStatus` [out]

Status from WDI for the *NdisWdiRxInorderDataIndication*. See the *Remarks* section for more information.

## Remarks

The RxEngine uses WDI_RX_INDICATION_DISPATCH_FIRST_OF_DPC if this indication is the first data indication **NdisWdiRxInorderDataIndication**) of a DPC. Subsequent data indications use WDI_RX_INDICATION_DISPATCH_GENERAL. If indications are made at passive level, then the RxEngine must use WDI_RX_INDICATION_PASSIVE. Indications made in the context of [MiniportWdiRxResume](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_rx_resume) must use WDI_RX_INDICATION_FROM_RX_RESUME_FRAMES. This parameter gives the RxMgr information necessary for limiting the lifetime of DPCs.

WDI_RX_INDICATION_FLAG_RESOURCES can be bitwise ORed with the other enum values to cause RxMgr to set NDIS_RECEIVE_FLAG_RESOURCES flags on the data indication.

The RxMgr issues [MiniportWdiRxGetMpdus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_rx_get_mpdus) requests to pull the received data.

If the target is not capable of RX frame classification and uses separate indications for RX frames from different PeerID/TID pairs, the PeerID is set to a wildcard (0xFFFF) and TID is set to WDI_EXT_TID_UNKNOWN.

In the case where the target/TAL takes full responsibility for reordering buffer management, it also performs all discard actions. No MPDU status is required.

PNDIS_RECEIVE_THROTTLE_PARAMETERS points to the *ReceiveThrottleParameters*, which is passed by NDIS for interrupts registered with NDIS. This only needs to be set for WDI_RX_INDICATION_DISPATCH_FIRST_OF_DPC. All other data indications should pass NULL, as this parameter is ignored.

If the RxMgr sets the WDI_STATUS to success, the RxEngine can create more data indications in the context of the same DPC. If the RxMgr sets the WDI_STATUS to pause, the RxEngine must not create data indications until the RxMgr issues a [MiniportWdiRxResume](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_rx_resume) and should exit dispatch level as soon as possible.

The RxEngine can choose how to handle incoming data while paused. If possible, it should just buffer the data. Dropping data is also acceptable.

The RxMgr tracks the number of frames indicated to NDIS against the limit specified in PNDIS_RECEIVE_THROTTLE_PARAMETERS. The RxMgr also tracks the time spent at dispatch. When limits are reached, the RxMgr returns NDIS_STATUS_PAUSED. The RxEngine should return/exit DPC as soon as possible, and must not indicate any more [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures (via **NdisWdiRxInorderDataIndication**) until RxMgr calls [MiniportWdiRxResume](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_rx_resume). Any **NET_BUFFER_LIST** structures that are given to RxMgr (via [MiniportWdiRxGetMpdus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_rx_get_mpdus)) and have not been indicated up yet are indicated up to NDIS in a different context to avoid spending too much time at DPC. Once that backlog has been cleared, RxMgr unpauses the RxEngine by invoking *MiniportWdiRxResume*.

## See also

[MiniportWdiRxGetMpdus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_rx_get_mpdus)

[MiniportWdiRxResume](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_rx_resume)

[NDIS_RECEIVE_THROTTLE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_receive_throttle_parameters)

[NDIS_WDI_DATA_API](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_data_api)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[WDI RX path](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-rx-path)

[WDI_EXTENDED_TID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-extended-tid)

[WDI_PEER_ID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-peer-id)

[WDI_RX_INDICATION_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ne-dot11wdi-_wdi_rx_indication_level)