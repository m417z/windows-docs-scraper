# KsDereferenceSoftwareBusObject function

## Description

*This function is intended for internal use only.*

The **KsDereferenceSoftwareBusObject** function decrements the reference count of the demand-load bus enumerator object's PDO.

## Parameters

### `Header` [in]

Pointer to the device header (extension) of the demand-load bus enumerator.

## Return value

None

## Remarks

A minidriver can access this function through the **DereferenceDeviceObject** member of the BUS_INTERFACE_SWENUM structure.

When the demand-load bus enumerator object's PDO reference count is 0, it becomes eligible for removal. Note that this condition does not guarantee removal.

## See also

[BUS_INTERFACE_SWENUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/swenum/ns-swenum-_bus_interface_swenum)

[KsQuerySoftwareBusInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/swenum/nf-swenum-ksquerysoftwarebusinterface)

[KsReferenceSoftwareBusObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/swenum/nf-swenum-ksreferencesoftwarebusobject)