# ResUtilGetSzProperty function

## Description

Retrieves a string property from a
[property list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-lists) and advances a pointer to the next property in
the list. The **PRESUTIL_GET_SZ_PROPERTY** type defines a pointer to this function.

## Parameters

### `ppszOutValue` [out]

Address of a pointer in which the string value from the property list will be returned.

### `pValueStruct` [in]

Pointer to a [CLUSPROP_SZ](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368390(v=vs.85)) structure specifying the
string value to retrieve from the property list.

### `pszOldValue` [in, optional]

Pointer to the previous value of the property.

### `ppPropertyList` [in, out]

Address of the pointer to the property list buffer containing the string property. This pointer will be
advanced to the beginning of the next property.

### `pcbPropertyListSize` [in, out]

Pointer to the size of the property list buffer. The size will be decremented to account for the advance of
the *ppPropertyList* pointer.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following is a possible error
code.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The data is formatted incorrectly. |

## See also

[ResUtilGetBinaryProperty](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetbinaryproperty)

[ResUtilGetDwordProperty](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetdwordproperty)

[ResUtilGetMultiSzProperty](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetmultiszproperty)