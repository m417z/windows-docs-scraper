# PropertiesListCopy function

## Description

This routine copies a properties list from source to target.

## Parameters

### `Target` [in]

Pointer to a collection list to copy to.

### `Source` [in]

Pointer to a collection list to copy.

## Return value

This function returns:

* STATUS_INVALID_PARAMETER if the Target or Source is nullptr.
* STATUS_BUFFER_TOO_SMALL if the Target collection list is not large enough to contain the content of the Source collection list.
* STATUS_SUCCESS if the copy was successful.

## Remarks

## See also