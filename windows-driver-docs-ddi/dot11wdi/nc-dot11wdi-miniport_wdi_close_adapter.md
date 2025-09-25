# MINIPORT_WDI_CLOSE_ADAPTER callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The MiniportWdiCloseAdapter handler function is used by the Microsoft component to initiate the Close Task operation on the IHV driver.

This is a WDI miniport handler inside [NDIS_MINIPORT_DRIVER_WDI_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_driver_wdi_characteristics).

This call must complete quickly. If the close operation is successfully started, the IHV must return NDIS_STATUS_SUCCESS and call the WDI [CloseAdapterComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_close_adapter_complete) handler that was passed into [MiniportWdiAllocateAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_allocate_adapter) with the [NDIS_WDI_INIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_init_parameters) structure.

**Note** You must declare the function by using the **MINIPORT_WDI_CLOSE_ADAPTER** type. For more
information, see the following Examples section.

## Parameters

### `MiniportAdapterContext` [in]

The handle to the context area that the miniport driver allocated.

## Return value

 MiniportWdiCloseAdapter can return any of the following return values.

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | MiniportWdiCloseAdapter successfully completed. |
| **Other NDIS_STATUS codes** | An appropriate NDIS_STATUS code in the case of a failure. |

## See also

[CloseAdapterComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_close_adapter_complete)

[MiniportWdiAllocateAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_allocate_adapter)

[NDIS_MINIPORT_DRIVER_WDI_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_driver_wdi_characteristics)

[NDIS_WDI_INIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_init_parameters)