# PropKeyFindKeyGetNthUshort function

## Description

This routine gets the nth USHORT value from a PROPVARIANT within a collection list based on the PROPERTYKEY.

## Parameters

### `pList` [in]

Pointer to the list of PROPVARIANT collection.

### `pKey` [in]

Pointer to a PROPERTYKEY for the target PROPVARIANT

### `Occurrence` [in]

Zero-based number of occurrence the PROPERTYKEY must be found before returning the value.

### `pRetValue` [out]

Pointer to the output buffer.

## Return value

This function returns one of the following NTSTATUS codes:

* STATUS_INVALID_PARAMETER if *pList*, *pKey* or, *pRetValue* is nullptr.
* STATUS_NOT_FOUND if the element at *Occurrence* was not found.
* STATUS_SUCCESS on success.

## Remarks

## See also