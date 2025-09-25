# MINIPORT_WDI_START_ADAPTER_OPERATION callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The MiniportWdiStartAdapterOperation handler function can be used by the IHV driver to perform any additional [MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) tasks. The IHV miniport can also use it as a hint that the Microsoft component has finished initializing the miniport and the miniport can start any needed background activities.

This is an optional WDI miniport handler inside [NDIS_MINIPORT_DRIVER_WDI_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_driver_wdi_characteristics).

**Note** You must declare the function by using the **MINIPORT_WDI_START_ADAPTER_OPERATION** type. For more
information, see the following Examples section.

## Parameters

### `MiniportAdapterContext` [in]

The handle to the context area that the miniport driver allocated.

## Return value

MiniportWdiStartAdapterOperation can return any of the following return values.

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | MiniportWdiStartAdapterOperation successfully completed. |
| **Other NDIS_STATUS codes** | An appropriate NDIS_STATUS code in the case of a failure. |

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_MINIPORT_DRIVER_WDI_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_driver_wdi_characteristics)