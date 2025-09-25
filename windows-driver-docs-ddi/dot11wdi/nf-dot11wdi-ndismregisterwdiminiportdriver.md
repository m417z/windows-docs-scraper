# NdisMRegisterWdiMiniportDriver function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

A miniport driver calls the NdisMRegisterWdiMiniportDriver function to register MiniportWdiXxx entry points with NDIS as the first step in initialization.

## Parameters

### `DriverObject` [in]

A pointer to an opaque driver object that the miniport driver received in its
[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine at the
*Argument1* parameter (see
[DriverEntry of NDIS
Miniport Drivers](https://learn.microsoft.com/windows-hardware/drivers/network/initializing-a-miniport-driver)).

### `RegistryPath` [in]

A pointer to an opaque registry path that the miniport driver received in its
[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine at the
*Argument2* parameter.

### `NdisDriverContext` [in, optional]

A handle to a driver-allocated context area where the driver maintains state and configuration
information.

### `MiniportDriverCharacteristics` [in]

A pointer to an
[NDIS_MINIPORT_DRIVER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_driver_characteristics) structure that the caller initialized.

### `MiniportWdiCharacteristics` [in]

A pointer to an [NDIS_MINIPORT_DRIVER_WDI_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_driver_wdi_characteristics) structure that the caller initialized.

### `NdisMiniportDriverHandle` [out]

A pointer to a caller-supplied handle variable. NDIS writes a handle to this variable that
uniquely identifies this driver. The driver must save this handle for use in subsequent
**Ndis*Xxx*** function calls.

## Return value

 NdisMRegisterWdiMiniportDriver can return any of the following return values.

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | NdisMRegisterWdiMiniportDriver registered the WDI miniport driver successfully. |
| **NDIS_STATUS_BAD_CHARACTERISTICS** | The *CharacteristicsLength* parameter is incorrect for the NDIS version that is specified at the **MajorNdisVersion** member in the structure at *MiniportDriverCharacteristics* . |
| **NDIS_STATUS_BAD_VERSION** | The **MajorNdisVersion** or **MinorNdisVersion** specified in the characteristics structure is invalid. |
| **NDIS_STATUS_RESOURCES** | A shortage of resources, possibly memory, prevented NDIS from registering the caller. |
| **NDIS_STATUS_FAILURE** | This is a default error status, returned when none of the preceding errors caused the registration to fail. |
| **Other NDIS_STATUS codes** | An appropriate NDIS_STATUS code in the case of a failure. |

## See also

[DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)

[NDIS_MINIPORT_DRIVER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_driver_characteristics)

[NDIS_MINIPORT_DRIVER_WDI_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_driver_wdi_characteristics)