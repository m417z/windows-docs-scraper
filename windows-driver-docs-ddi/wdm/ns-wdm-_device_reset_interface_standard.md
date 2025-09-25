# _DEVICE_RESET_INTERFACE_STANDARD structure

## Description

The **DEVICE_RESET_INTERFACE_STANDARD** structure enables function drivers to reset and recover malfunctioning devices. This structure describes the GUID_DEVICE_RESET_INTERFACE_STANDARD interface.

For more information see [Working with the GUID_DEVICE_RESET_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/kernel/working-with-guid-device-reset-interface-standard).

## Members

### `Size`

The size, in bytes, of this structure.

### `Version`

The driver-defined interface version.

### `Context`

A pointer to interface-specific context information.

### `InterfaceReference`

A pointer to an [InterfaceReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_reference) routine that increments the interface's reference count.

### `InterfaceDereference`

A pointer to an [InterfaceDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference) routine that decrements the interface's reference count.

### `DeviceReset`

A pointer to the interface's [DeviceReset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-device_reset_handler) routine. This routine can be used by function drivers to attempt to reset and recover a malfunctioning device.

### `SupportedResetTypes`

Defines the **ULONG** parameter *SupportedResetTypes*.

### `Reserved`

Reserved for future use.

### `QueryBusSpecificResetInfo`

Defines the **PDEVICE_QUERY_BUS_SPECIFIC_RESET_HANDLER** parameter *QueryBusSpecificResetInfo*.

### `DeviceBusSpecificReset`

Defines the **PDEVICE_BUS_SPECIFIC_RESET_HANDLER** parameter *DeviceBusSpecificReset*.

### `GetDeviceResetStatus`

Defines the **PGET_DEVICE_RESET_STATUS** parameter *GetDeviceResetStatus*.

## Remarks

The **DEVICE_RESET_INTERFACE_STANDARD** structure is an extension of the [INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure. A driver obtains a pointer to the **DEVICE_RESET_INTERFACE_STANDARD** structure by sending an [IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface) IRP to its bus driver with **InterfaceType** set to GUID_DEVICE_RESET_INTERFACE_STANDARD.

For more information about the purpose of this interface, see [Working with the GUID_DEVICE_RESET_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/kernel/working-with-guid-device-reset-interface-standard).

## See also

[DeviceReset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-device_reset_handler)

[INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface)

[IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface)

[InterfaceDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference)

[InterfaceReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_reference)