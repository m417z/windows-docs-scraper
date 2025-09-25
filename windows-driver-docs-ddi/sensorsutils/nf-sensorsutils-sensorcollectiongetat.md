# SensorCollectionGetAt function

## Description

This routine returns the PROPERTYKEY and PROPVARIANT associated with the nth element in the provided sensor collection list.

## Parameters

### `Index` [in]

Zero-based index of the element in the pSensorsList.

### `pSensorsList` [in]

Pointer to a sensor collection list.

### `pKey` [out]

Size of data.

### `pValue` [out]

Location of the data.

## Return value

This function returns STATUS_NOT_FOUND if not found, STATUS_SUCCESS otherwise.

## Remarks

## See also