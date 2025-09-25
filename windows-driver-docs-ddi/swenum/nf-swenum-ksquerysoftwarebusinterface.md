# KsQuerySoftwareBusInterface function

## Description

*This function is intended for internal use only.*

The **KsQuerySoftwareBusInterface** function creates a buffer from the paged pool and copies the reference string associated with the demand-load bus enumerator object's PDO into the buffer. It is the caller's responsibility to free the buffer using [ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool).

## Parameters

### `PnpDeviceObject` [in]

Pointer to the demand-load bus enumerator's device object.

### `BusInterface` [out]

Pointer to the demand-load bus enumerator's interface.

## Return value

Returns STATUS_SUCCESS if the request is handled. Otherwise, it returns an appropriate error code.

## Remarks

A minidriver can access this function through the **QueryReferenceString** member of the BUS_INTERFACE_SWENUM structure.

## See also

[BUS_INTERFACE_SWENUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/swenum/ns-swenum-_bus_interface_swenum)

[KsDereferenceSoftwareBusObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/swenum/nf-swenum-ksdereferencesoftwarebusobject)

[KsReferenceSoftwareBusObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/swenum/nf-swenum-ksreferencesoftwarebusobject)