# PINTERFACE_DEREFERENCE callback function (wdm.h)

## Description

The *InterfaceDereference* routine decrements the reference count on a driver-defined interface.

## Parameters

### `Context` [in]

A pointer to interface-specific context information. The caller passes the value that is passed as the **Context** member of the [INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure for the interface.

Note that the *InterfaceDereference* routine is a per interface contract, so there are no general IRQL requirements for calling it.

## Remarks

You can use the [InterfaceReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_reference) routine to increment the reference count for the interface.

The driver that imports the interface is responsible for calling the *InterfaceDereference* routine to decrement the reference count after the driver is no longer using the interface. For example, a driver that requests a pointer to the interface by sending an [IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface) request calls *InterfaceDereference*. Also, a driver that receives a pointer to the interface to another driver must call *InterfaceDereference*.

## See also

[INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface)

[IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface)

[InterfaceReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_reference)