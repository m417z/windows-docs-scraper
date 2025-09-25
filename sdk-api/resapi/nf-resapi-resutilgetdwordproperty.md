# ResUtilGetDwordProperty function

## Description

Retrieves a
**DWORD** property from a
[property list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-lists) and advances a pointer to the next property in
the list. The **PRESUTIL_GET_DWORD_PROPERTY** type defines a pointer to this function.

## Parameters

### `pdwOutValue` [out]

Address of a pointer in which the **DWORD** value from the property list will be
returned.

### `pValueStruct` [in]

Pointer to a [CLUSPROP_DWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368375(v=vs.85)) structure specifying
the **DWORD** value to retrieve from the property list.

### `dwOldValue` [in]

Specifies the previous value of the property.

### `dwMinimum` [in]

Specifies the minimum value allowed for the property.

### `dwMaximum` [in]

Specifies the maximum value allowed for the property.

### `ppPropertyList` [out]

Address of the pointer to the property list buffer containing the **DWORD**
property. This pointer will be advanced to the beginning of the next property.

### `pcbPropertyListSize` [out]

Pointer to the size of the property list buffer. The size will be decremented to account for the advance of
the *ppPropertyList* pointer.

## Return value

If the operations succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following is a possible error
code.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The data is formatted incorrectly. |

## Remarks

The **ResUtilGetDwordProperty** utility function verifies that the value returned
in *pdwOutValue* is within the range specified by *dwMinimum* and
*dwMaximum*. If *dwMinimum* and
*dwMaximum* are both set to 0, no range checking is done.

## See also

[ResUtilGetBinaryProperty](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetbinaryproperty)

[ResUtilGetMultiSzProperty](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetmultiszproperty)

[ResUtilGetSzProperty](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetszproperty)