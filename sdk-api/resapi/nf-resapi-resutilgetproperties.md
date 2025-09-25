# ResUtilGetProperties function

## Description

Retrieves properties specified by a [property table](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-tables) from
the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) and returns them in a
[property list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-lists). The
**PRESUTIL_GET_PROPERTIES** type defines a pointer to this function.

## Parameters

### `hkeyClusterKey` [in]

Pointer to the cluster database key that identifies the location of the properties to retrieve.

### `pPropertyTable` [in]

Pointer to an array of [RESUTIL_PROPERTY_ITEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resutil_property_item) structures that describe the properties to retrieve.

### `pOutPropertyList` [out]

Pointer to an output buffer in which to return the property list.

### `cbOutPropertyListSize` [in]

Size in bytes of the output buffer pointed to by *pOutPropertyList*.

### `pcbBytesReturned` [out]

Pointer to the total number of bytes in the property list pointed to by *pOutPropertyList*.

### `pcbRequired` [out]

Pointer to the number of bytes that is required if *pOutPropertyList* is too small.

## Return value

If the operations succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following are possible error codes.

| Return code | Description |
| --- | --- |
| **ERROR_BAD_ARGUMENTS** | One or more of the input parameters were invalid. |
| **ERROR_MORE_DATA** | The output buffer was too small to contain the resulting data. The *pcbRequired* parameter indicates the required size. |
| **ERROR_NOT_ENOUGH_MEMORY** | There was an error allocating memory. |

## See also

[ResUtilGetPrivateProperties](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetprivateproperties)