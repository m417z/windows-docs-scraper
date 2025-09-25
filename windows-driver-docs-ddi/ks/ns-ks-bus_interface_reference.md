# BUS_INTERFACE_REFERENCE structure

## Description

A software device enumerator exports this interface to allow drivers to reference count physical device objects (PDOs) such that the device remains active while in use and is unloaded when not in use.

## Members

### `Interface`

Specifies the exported [INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface).

### `ReferenceDeviceObject`

Pointer to a driver-supplied [KStrReferenceDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnreferencedeviceobject) routine.

### `DereferenceDeviceObject`

Pointer to a driver-supplied [KStrDereferenceDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfndereferencedeviceobject) routine.

### `QueryReferenceString`

Pointer to a driver-supplied [KStrQueryReferenceString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnqueryreferencestring) routine.

## Remarks

A driver obtains a BUS_INTERFACE_REFERENCE interface by creating and sending an IRP_MJ_PNP request that specifies an [IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface) minor function code. To do this, the driver should:

* Allocate and zero-fill a BUS_INTERFACE_REFERENCE structure from the paged memory pool.
* Create an IRP for the query interface request and get the next stack location for the new IRP.
* In the new stack location, provide a pointer to the new BUS_INTERFACE_REFERENCE structure in the **Parameters.QueryInterface.Interface** member.
* Set a completion routine and send the request down the driver stack.
* If your request is successful, the system fills in the BUS_INTERFACE_REFERENCE structure pointed to by **Parameters.QueryInterface.Interface**.