# KsReferenceSoftwareBusObject function

## Description

*This function is intended for internal use only.*

The **KsReferenceSoftwareBusObject** function increments the reference count of the demand-load bus enumerator object's PDO.

## Parameters

### `Header` [in]

Pointer to the device header (extension) of the demand-load bus enumerator.

## Return value

Returns STATUS_SUCCESS if the request is handled. Otherwise, it returns an appropriate error code.

## Remarks

A minidriver can access this function through the **ReferenceDeviceObject** member of the BUS_INTERFACE_SWENUM structure.

The device object remains active and enumerated until the reference count returns to 0.

## See also

[BUS_INTERFACE_SWENUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/swenum/ns-swenum-_bus_interface_swenum)

[KsDereferenceSoftwareBusObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/swenum/nf-swenum-ksdereferencesoftwarebusobject)

[KsQuerySoftwareBusInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/swenum/nf-swenum-ksquerysoftwarebusinterface)