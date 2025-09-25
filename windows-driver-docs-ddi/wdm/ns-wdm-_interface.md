## Description

The **INTERFACE** structure describes an interface that is exported by a driver for use by other drivers.

## Members

### `Size`

Size, in bytes, of a structure defining a driver interface, including this structure and interface-specific members.

### `Version`

Driver-defined interface version.

### `Context`

Pointer to interface-specific context information.

### `InterfaceReference`

Pointer to a driver-supplied [InterfaceReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_reference) routine that increments the interface's reference count.

### `InterfaceDereference`

Pointer to a driver-supplied [InterfaceDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference) routine that decrements the interface's reference count.

## Remarks

The **INTERFACE** structure must be included as the first member of all structures that describe interfaces returned by drivers in response to an [IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface) request.

The *InterfaceReference* routine must be called by the driver that exports the interface, each time the driver supplies that interface in response to **IRP_MN_QUERY_INTERFACE**. Likewise, if the driver that requests the interface subsequently passes it to another driver, the driver that passes the interface must call *InterfaceReference* on behalf of the driver that receives it.

Each driver that imports the interface (whether by sending **IRP_MN_QUERY_INTERFACE** or by receiving the interface from another driver) must call the *InterfaceDereference* routine after it has finished using the interface. After calling the *InterfaceDereference* routine, a driver cannot use the interface again without first reobtaining it.

When introducing a new version of an existing interface, create a new GUID instead of revising the **Size** or **Version** fields of this structure. For more info, see [Using Driver-Defined Interfaces](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-driver-defined-interfaces).

## See also

[IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface)

[InterfaceDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference)