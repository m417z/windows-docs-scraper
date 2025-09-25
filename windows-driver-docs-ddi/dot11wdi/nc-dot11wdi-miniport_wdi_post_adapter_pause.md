# MINIPORT_WDI_POST_ADAPTER_PAUSE callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The MiniportWdiPostAdapterPause handler function is called by the Microsoft component after it finishes the data path clean up as part of the NDIS [MiniportPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pause) requirements.

This is a WDI miniport handler inside [NDIS_MINIPORT_DRIVER_WDI_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_driver_wdi_characteristics).

The NDIS [MiniportPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pause) requirements are handled by the Microsoft component. As part of *MiniportPause*, it stops the data path and waits for it to clean up. The WDI IHV miniport can optionally register for a *MiniportWdiPostAdapterPause* callback that is called by the Microsoft component after it finishes the data path cleanup.

**Note** You must declare the function by using the **MINIPORT_WDI_POST_ADAPTER_PAUSE** type. For more
information, see the following Examples section.

## Parameters

### `MiniportAdapterContext` [in]

The handle to the context area that the miniport driver allocated.

### `PauseParameters` [in]

A pointer to an [NDIS_MINIPORT_PAUSE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_pause_parameters) structure that defines the pause parameters for the miniport adapter.

## Return value

The return value is only used for logging/informational purposes.

## See also

[MiniportPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pause)

[NDIS_MINIPORT_DRIVER_WDI_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_driver_wdi_characteristics)

[NDIS_MINIPORT_PAUSE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_pause_parameters)