# _PNP_LOCATION_INTERFACE structure

## Description

The **PNP_LOCATION_INTERFACE** structure describes the [GUID_PNP_LOCATION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/adding-a-pnp-device-to-a-running-system#using-guid_pnp_location_interface) interface.

## Members

### `Size`

The size, in bytes, of this structure.

### `Version`

The driver-defined version of the interface.

### `Context`

A pointer to interface-specific context information.

### `InterfaceReference`

A pointer to an [InterfaceReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_reference) routine that increments the reference count for the interface. The PINTERFACE_REFERENCE function pointer type is defined in the Wdm.h header file.

### `InterfaceDereference`

A pointer to an [InterfaceDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference) routine that decrements the reference count for the interface. The PINTERFACE_DEREFERENCE function pointer type is defined in the Wdm.h header file.

### `GetLocationString`

A pointer to the [PnpGetLocationString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pget_location_string) routine for the interface. The routine supplies the device-specific part of the SPDRP_LOCATION_PATHS property for the device.

## Remarks

A driver obtains a pointer to the **PNP_LOCATION_INTERFACE** structure by sending an [IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface) IRP to its bus driver with **InterfaceType** set to GUID_PNP_LOCATION_INTERFACE.

## See also

[IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface)

[InterfaceDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference)

[InterfaceReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_reference)

[PnpGetLocationString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pget_location_string)