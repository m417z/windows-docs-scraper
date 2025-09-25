# PropKeyFindKeyGetDouble function

## Description

This routine gets a double precision floating point value from a PROPVARIANT within a collection list based on the PROPERTYKEY.

## Parameters

### `pList` [in]

Pointer to the list of PROPVARIANT collection.

### `pKey` [in]

Pointer to a PROPERTYKEY for the target PROPVARIANT.

### `pRetValue` [out]

Pointer to a PROPERTYKEY for the target PROPVARIANT.

## Return value

This function returns an NTSTATUS code that represents:

* STATUS_INVALID_PARAMETER if pList, pKey or, pRetValue is nullptr.
* STATUS_NOT_FOUND if the element identified by pKey was not found.
* STATUS_SUCCESS if the function was successful.

## Remarks

## See also