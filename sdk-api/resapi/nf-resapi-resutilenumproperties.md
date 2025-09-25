# ResUtilEnumProperties function

## Description

Enumerates the property names of a [cluster object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects). The **PRESUTIL_ENUM_PROPERTIES** type defines a pointer to this function.

## Parameters

### `pPropertyTable` [in]

Pointer to an array of [RESUTIL_PROPERTY_ITEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resutil_property_item) structures describing properties to enumerate.

### `pszOutProperties` [out]

Pointer to the output buffer in which to return the names of all of the properties in multiple string format. Each property name is stored as a null-terminated Unicode string. The last property name is followed by a final null-terminating character.

### `cbOutPropertiesSize` [in]

Size in bytes of the output buffer pointed to by *pszOutProperties*.

### `pcbBytesReturned` [out]

Pointer to the total number of bytes in the property list pointed to by *pszOutProperties*.

### `pcbRequired` [out]

Number of bytes required if the output buffer is too small.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following are possible error codes.

| Return code | Description |
| --- | --- |
| **ERROR_BAD_ARGUMENTS** | One or more of the input parameters were invalid. |
| **ERROR_NOT_ENOUGH_MEMORY** | There was an error allocating memory. |
| **ERROR_MORE_DATA** | The size of the output buffer is too small to hold the resulting data. The *pcbRequired* parameter points to the correct size. |

## See also

[RESUTIL_PROPERTY_ITEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resutil_property_item)