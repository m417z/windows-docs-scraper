# NDIS_WDI_TX_QUERY_SUSPECT_FRAME_COMPLETE_STATUS callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The *TxQuerySuspectFrameStatus* callback function is implemented by the IHV miniport to query the status of a suspect frame.

## Parameters

### `NdisMiniportDataPathHandle`

The NdisMiniportDataPathHandle passed to the IHV miniport in [MiniportWdiTalTxRxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_initialize).

### `SuspectFrameContext`

Context information about the suspect frame.

### `pNBL`

A pointer to the suspect frame.

### `pIsTransferCompleteNeeded`

A pointer to a BOOLEAN value that indicates if the frame requires the transfer completion callback to be invoked.

### `pIsSendCompleteNeeded`

A pointer to a BOOLEAN value that indicates if the frame requires the send completion callback to be invoked.

### `pWifiStatus`

A pointer to the status set by the IHV miniport to indicate the result of *TxQuerySuspectFrameStatus*.

## Prototype

```cpp
//Declaration

NDIS_WDI_TX_QUERY_SUSPECT_FRAME_COMPLETE_STATUS NdisWdiTxQuerySuspectFrameCompleteStatus;

// Definition

void NdisWdiTxQuerySuspectFrameCompleteStatus
(
	NDIS_HANDLE NdisMiniportDataPathHandle
	UINT64 SuspectFrameContext
	PNET_BUFFER_LIST pNBL
	BOOLEAN *pIsTransferCompleteNeeded
	BOOLEAN *pIsSendCompleteNeeded
	NDIS_STATUS *pWifiStatus
)
{...}

```

## Remarks

Register your implementation of this callback function by setting the appropriate member of the [NDIS_WDI_DATA_API](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_data_api) structure.

This callback is typically called from the context of the [*TxSuspectFrameListAbort*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tx_suspect_frame_list_abort) callback function.

## See also