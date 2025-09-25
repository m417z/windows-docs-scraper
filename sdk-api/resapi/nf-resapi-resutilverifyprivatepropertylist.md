# ResUtilVerifyPrivatePropertyList function

## Description

Verifies that a [property list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-lists) is correctly formatted.

## Parameters

### `pInPropertyList` [in]

Pointer to an input buffer containing the property list to verify.

### `cbInPropertyListSize` [in]

Size of the input buffer pointed to by *pInPropertyList*.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[ResUtilSetPrivatePropertyList](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetprivatepropertylist)