# NDIS_WDI_ALLOCATE_WDI_FRAME_METADATA callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The NdisWdiAllocateWiFiFrameMetaData callback function allocates a frame metadata buffer.

This is a callback inside [NDIS_WDI_DATA_API](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_data_api).

## Parameters

### `NdisMiniportDataPathHandle` [in]

The NdisMiniportDataPathHandle passed to the IHV miniport in [MiniportWdiTalTxRxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_initialize).

## Return value

The allocated frame metadata buffer.

## See also

[NDIS_WDI_DATA_API](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_data_api)

[WDI_FRAME_METADATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_wdi_frame_metadata)