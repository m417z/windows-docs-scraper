# MINIPORT_WDI_POST_ADAPTER_RESTART callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The MiniportWdiPostAdapterRestart handler function is called by the Microsoft component after it finishes restarting the data path as part of the NDIS [MiniportRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_restart) requirements.

This is a WDI miniport handler inside [NDIS_MINIPORT_DRIVER_WDI_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_driver_wdi_characteristics).

The NDIS [MiniportRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_restart) requirements are handled by the Microsoft component. As part of *MiniportRestart*, it undoes the data path pause work that it performed as part of [MiniportPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pause). The WDI IHV miniport can optionally register for a *MiniportWdiPostAdapterRestart* callback that is called by the Microsoft component after it finishes restarting the data path.

**Note** You must declare the function by using the **MINIPORT_WDI_POST_ADAPTER_RESTART** type. For more
information, see the following Examples section.

## Parameters

### `MiniportAdapterContext` [in]

The handle to the context area that the miniport driver allocated.

### `RestartParameters` [in]

A pointer to an [NDIS_MINIPORT_RESTART_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_restart_parameters) structure that defines the restart parameters for the miniport adapter.

## Return value

MiniportWdiPostAdapterRestart can return any of the following return values.

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The driver successfully restarted the flow of network data through the miniport adapter. |
| **NDIS_STATUS_RESOURCES** | The restart failed because of insufficient resources. |
| **NDIS_STATUS_FAILURE** | The driver indicates **NDIS_STATUS_FAILURE** if none of the preceding values applies. |

## See also

[MiniportPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pause)

[MiniportRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_restart)

[NDIS_MINIPORT_DRIVER_WDI_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_driver_wdi_characteristics)

[NDIS_MINIPORT_RESTART_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_restart_parameters)