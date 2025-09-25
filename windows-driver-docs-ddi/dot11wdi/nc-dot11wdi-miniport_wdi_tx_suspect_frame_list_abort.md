# MINIPORT_WDI_TX_SUSPECT_FRAME_LIST_ABORT callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The *TxSuspectFrameListAbort* callback function is implemented by the IHV miniport to inform the TxEngine that the TxMgr has identified frames which are suspected of being hung or pending completion for a significant length of time.

## Parameters

### `MiniportTalTxRxContext`

The TAL device handle returned by the IHV miniport in [MiniportWdiTalTxRxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_initialize).

### `SuspectFrameContext`

Context information about the suspected frame.

### `NumSuspectFrames`

The number of suspect frames.

### `SuspectFrameList`

The list of suspected frames. For more information, see the Remarks section.

## Prototype

```cpp
//Declaration

MINIPORT_WDI_TX_SUSPECT_FRAME_LIST_ABORT MiniportWdiTxSuspectFrameListAbort;

// Definition

void MiniportWdiTxSuspectFrameListAbort
(
	TAL_TXRX_HANDLE MiniportTalTxRxContext
	UINT64 SuspectFrameContext
	UINT16 NumSuspectFrames
	PNET_BUFFER_LIST *SuspectFrameList
)
{...}

```

## Remarks

Register your implementation of this callback function by setting the appropriate member of the [NDIS_MINIPORT_WDI_DATA_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_wdi_data_handlers) structure.

This is an optional handler. If the IHV miniport does not implement this callback's behavior, it should not set the function pointer in [NDIS_MINIPORT_WDI_DATA_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_wdi_data_handlers) and WDI will not call this handler. However, if this callback's behavior is not implemented, the function pointer might still be set if the IHV miniport uses the *SuspectFrameList* to log IHV state for diagnostic purposes.

This callback function informs the TxEngine that the TxMgr has identified frames which are suspected of being hung or pending completion for a significant length of time. The *SuspectFrameList* array of NBL pointers, of which the **Next** pointer is not applicable, represent frames which the TxMgr is requesting prompt completion even if that results in the frame not being transmitted over the air.

The TxEngine might check the status of an NBL in the *SuspectFrameList* array by calling [*TxQuerySuspectFrameStatus*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_query_suspect_frame_complete_status) from the context of *TxSuspectFrameListAbort* with the *SuspectFrameContext* passed to the handler. The TxMgr will not call [TxTargetDescDeinit](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tx_target_desc_deinit) for any NBLs in *SuspectFrameList* during the duration of *TxSuspectFrameAbort*, nor will it complete the frames to NDIS.

If the TxEngine or firmware has no knowledge or state for the suspect frame it should not issue completions for that suspect frame, as this might cause system corruption and/or double completions.

If a firmware stall or corruption is detected, an [NDIS_STATUS_WDI_INDICATION_FIRMWARE_STALLED](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wdi-indication-firmware-stalled) notification should be made to attempt recovery.

## See also