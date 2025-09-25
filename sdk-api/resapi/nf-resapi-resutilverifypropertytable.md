# ResUtilVerifyPropertyTable function

## Description

Uses a [property table](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-tables) to verify that a [property list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-lists) is correctly formatted.

## Parameters

### `pPropertyTable` [in]

Pointer to a property table describing the properties that will be validated in the property list.

### `Reserved`

This parameter is reserved for future use.

### `bAllowUnknownProperties` [in]

If **TRUE**, the function ignores all properties in the property list that are not included in the property table. If **FALSE**, any property in the property list that is not included in the property table causes the function to return **ERROR_INVALID_PARAMETER**.

### `pInPropertyList` [in]

Pointer to the input buffer containing the property list to validate.

### `cbInPropertyListSize` [in]

Size in bytes of the input buffer pointed to by *pInPropertyList*.

### `pOutParams` [out, optional]

Pointer to a parameter block.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following are possible error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The property list buffer is larger than reported by the *cbInPropertyListSize* parameter. |
| **ERROR_INVALID_DATA** | No property list buffer was specified, or the property list is formatted incorrectly |
| **ERROR_INVALID_PARAMETER** | The property list is formatted incorrectly. If *bAllowUnknownProperties* is set to **FALSE**, the property list may contain properties that are not present in the property table. |

## See also

[RESUTIL_PROPERTY_ITEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resutil_property_item)