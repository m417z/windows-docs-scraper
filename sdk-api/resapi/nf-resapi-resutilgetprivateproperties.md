# ResUtilGetPrivateProperties function

## Description

Returns [private properties](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/private-properties) for a [cluster object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects). The **PRESUTIL_GET_PRIVATE_PROPERTIES** type defines a pointer to this function.

## Parameters

### `hkeyClusterKey` [in]

Pointer to the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) key that identifies the location of the private properties to retrieve.

### `pOutPropertyList` [out]

Pointer to an output buffer in which a [property list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-lists) with the names and values of the private properties is returned.

### `cbOutPropertyListSize` [in]

Size of the output buffer pointed to by *pOutPropertyList*.

### `pcbBytesReturned` [out]

Pointer to the total number of bytes in the property list pointed to by *pOutPropertyList*.

### `pcbRequired` [out]

Pointer to the number of bytes that is required if *pOutPropertyList* is too small to hold all of the private properties.

## Return value

If the operations succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following are possible error codes.

| Return code | Description |
| --- | --- |
| **ERROR_BAD_ARGUMENTS** | One or more of the input parameters were invalid. |
| **ERROR_NOT_ENOUGH_MEMORY** | There was an error allocating memory. |
| **ERROR_MORE_DATA** | The size of the output buffer is too small to hold the resulting data. The *pcbRequired* parameter points to the correct size. |

## See also

[ResUtilGetProperties](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetproperties)