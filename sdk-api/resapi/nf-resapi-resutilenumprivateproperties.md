# ResUtilEnumPrivateProperties function

## Description

Retrieves the names of a [cluster object's](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects) [private properties](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/private-properties). The **PRESUTIL_ENUM_PRIVATE_PROPERTIES** type defines a pointer to this function.

## Parameters

### `hkeyClusterKey` [in]

Key identifying the location of the private properties in the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database).

### `pszOutProperties` [out]

Pointer to an output buffer in which to receive the names of the enumerated properties.

### `cbOutPropertiesSize` [in]

Size of the output buffer pointed to by *pszOutProperties*.

### `pcbBytesReturned` [out]

Pointer to the total number of bytes returned in the output buffer.

### `pcbRequired` [out]

Pointer to the required number of bytes if the output buffer is too small to hold all of the enumerated properties.

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

[ResUtilEnumProperties](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilenumproperties)