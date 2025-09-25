# _REENUMERATE_SELF_INTERFACE_STANDARD structure

## Description

The **REENUMERATE_SELF_INTERFACE_STANDARD** interface structure enables a driver to request that its parent bus driver reenumerate the driver's device. This structure defines the [GUID_REENUMERATE_SELF_INTERFACE_STANDARD](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546570(v=vs.85)) interface.

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

### `SurpriseRemoveAndReenumerateSelf`

A pointer to a [ReenumerateSelf](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-preenumerate_self) routine that requests device reenumeration.

## Remarks

A driver obtains a pointer to the **REENUMERATE_SELF_INTERFACE_STANDARD** structure by sending an [IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface) IRP to its bus driver with **InterfaceType** set to GUID_REENUMERATE_SELF_INTERFACE_STANDARD.

The **REENUMERATE_SELF_INTERFACE_STANDARD** structure is an extension of the [INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure.

## See also

[GUID_REENUMERATE_SELF_INTERFACE_STANDARD](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546570(v=vs.85))

[INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface)

[IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface)

[InterfaceDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference)

[InterfaceReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_reference)

[ReenumerateSelf](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-preenumerate_self)