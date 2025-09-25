# _BUS_INTERFACE_SWENUM structure

## Description

The BUS_INTERFACE_SWENUM structure describes the demand-load bus enumerator object's interface.

## Members

### `Interface`

Specifies the exported [INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface).

### `ReferenceDeviceObject`

Pointer to a driver-supplied [KsReferenceSoftwareBusObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/swenum/nf-swenum-ksreferencesoftwarebusobject) routine.

### `DereferenceDeviceObject`

Pointer to a driver-supplied [KsDereferenceSoftwareBusObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/swenum/nf-swenum-ksdereferencesoftwarebusobject) routine.

### `QueryReferenceString`

Pointer to a driver-supplied [KsQuerySoftwareBusInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/swenum/nf-swenum-ksquerysoftwarebusinterface) routine.

## Remarks

A driver obtains a BUS_INTERFACE_SWENUM interface by creating and sending an IRP_MJ_PNP request that specifies an [IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface) minor function code. To do this, the driver should:

* Allocate and zero-fill a BUS_INTERFACE_SWENUM structure from the paged memory pool.
* Create an IRP for the query interface request and get the next stack location for the new IRP.
* In the new stack location, provide a pointer to the new BUS_INTERFACE_SWENUM structure in the **Parameters.QueryInterface.Interface** member.
* Set a completion routine and send the request down the driver stack.
* If your request is successful, the system fills in the BUS_INTERFACE_SWENUM structure pointed to by **Parameters.QueryInterface.Interface**.