# KsGetBusEnumParentFDOFromChildPDO function

## Description

*This function is intended for internal use only.*

The **KsGetBusEnumParentFDOFromChildPDO** function retrieves the FDO of the parent of the given child PDO.

## Parameters

### `DeviceObject` [in]

Pointer to the child's PDO.

### `FunctionalDeviceObject` [out]

Pointer to the device object to receive the parent's FDO.

## Return value

Returns STATUS_SUCCESS if successful, or STATUS_INVALID_PARAMETER if *DeviceObject* does not contain a device extension, or if the device extension specified in *DeviceObject* is not that of a PDO.