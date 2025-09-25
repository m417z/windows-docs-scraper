# MINIPORT_WDI_ALLOCATE_ADAPTER callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The MiniportWdiAllocateAdapter handler function allocates a WDI miniport adapter.

This is a WDI miniport handler inside [NDIS_MINIPORT_DRIVER_WDI_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_driver_wdi_characteristics).

**Note** You must declare the function by using the **MINIPORT_WDI_ALLOCATE_ADAPTER** type. For more
information, see the following Examples section.

## Parameters

### `NdisMiniportHandle` [in]

The NDIS-supplied handle that identifies the miniport adapter.

### `MiniportDriverContext` [in]

The handle to a driver-allocated context area where the driver maintains state and configuration information. The miniport driver passed this context area to the [NdisMRegisterWdiMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nf-dot11wdi-ndismregisterwdiminiportdriver) function.

### `MiniportInitParameters` [in]

A pointer to an [NDIS_MINIPORT_INIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_init_parameters) structure that defines the initialization parameters for the miniport adapter.

### `NdisWdiInitParameters` [in]

A pointer to an [NDIS_WDI_INIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_init_parameters) structure that defines the WDI initialization parameters for the miniport adapter.

### `RegistrationAttributes` [in, out]

A pointer to an [NDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_registration_attributes) structure that defines registration attributes that are associated with the miniport adapter.

## Return value

 MiniportWdiAllocateAdapter can return any of the following return values.

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | MiniportWdiAllocateAdapter successfully completed. |
| **NDIS_STATUS_RESOURCES** | MiniportWdiAllocateAdapter could not allocate the necessary resources. |

## See also

[NDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_registration_attributes)

[NDIS_MINIPORT_DRIVER_WDI_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_driver_wdi_characteristics)

[NDIS_MINIPORT_INIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_init_parameters)

[NDIS_WDI_INIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_init_parameters)