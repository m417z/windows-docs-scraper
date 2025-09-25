# PropKeyFindKeyGetPropVariant function

## Description

This routine finds the PROPVARIANT from a collection list based on the PROPERTYKEY.

## Parameters

### `pList` [in]

Pointer to the list of PROPVARIANT collection.

### `pKey` [in]

Pointer to a PROPERTYKEY for the target PROPVARIANT.

### `TypeCheck` [in]

If TRUE, the function validates whether a *pValue* type matches one of the value types found in *pList*.

### `pValue` [in/out]

Pointer to the target PROPVARIANT.

## Return value

This function returns one of the following NTSTATUS codes:

* STATUS_INVALID_PARAMETER if *pList*, *pKey* or, *pValue* is nullptr.
* STATUS_NOT_FOUND if the element associated with the propertyKey was not found.
* STATUS_SUCCESS on success.

## Remarks

## See also