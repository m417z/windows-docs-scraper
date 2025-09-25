# KsIsBusEnumChildDevice function

## Description

*This function is intended for internal use only.*

The **KsIsBusEnumChildDevice** function determines if the given device object is a child device of the demand-load bus enumerator object.

## Parameters

### `DeviceObject` [in]

Pointer to a device object.

### `ChildDevice` [out]

Pointer to a BOOLEAN to receive the result. **KsIsBusEnumChildDevice** sets this to **TRUE** if the given device object is a child device of the demand-load bus enumerator object, or **FALSE** otherwise.

## Return value

Returns STATUS_SUCCESS if the given device object's device extension is valid; otherwise, it returns an error code.