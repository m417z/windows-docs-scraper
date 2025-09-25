# NDIS_WDI_CLOSE_ADAPTER_COMPLETE callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The NdisWdiCloseAdapterComplete callback function is called by the IHV when a Close Task operation from [MiniportWdiCloseAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_close_adapter) has been successfully started.

This is a control path callback inside [NDIS_WDI_INIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_init_parameters).

## Parameters

### `MiniportAdapterHandle` [in]

The miniport handle.

### `CompletionStatus` [in]

The completion status.

## See also

[MiniportWdiCloseAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_close_adapter)

[NDIS_WDI_INIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_init_parameters)