# PINTERFACE_REFERENCE callback function (wdm.h)

## Description

The *InterfaceReference* routine increments the reference count on a driver-defined interface.

## Parameters

### `Context` [in]

A pointer to interface-specific context information. The caller passes the value that is passed as the **Context** member of the [INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure for the interface.

## Remarks

Note that this is a per interface contract, so there are no general IRQL requirements around InterfaceReference/Dereference.

You can use the [InterfaceDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference) routine to decrement the reference count for the interface.

The driver that exports the interface is responsible for calling *InterfaceReference* to increment the reference count before the driver exports the interface. For example, the driver that initially exported the interface in response to an [IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface) request calls *InterfaceReference*. Also, a driver that passes a pointer to the interface to another driver must call *InterfaceReference*.

Note that the *InterfaceReference* routine is a per interface contract, so there are no general IRQL requirements for calling it.

## See also

[INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface)

[IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface)

[InterfaceDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference)