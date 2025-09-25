# ResUtilGetProperty function

## Description

Returns a specified property from the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database). The **PRESUTIL_GET_PROPERTY** type defines a pointer to this function.

## Parameters

### `hkeyClusterKey` [in]

Pointer to the cluster database key identifying the location of the property to retrieve.

### `pPropertyTableItem` [in]

Pointer to a [RESUTIL_PROPERTY_ITEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resutil_property_item) structure that describes the property to retrieve.

### `pOutPropertyItem` [out]

Pointer to an output buffer in which to return the requested property. It is assumed that the buffer is part of a [property list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-lists).

### `pcbOutPropertyItemSize` [in, out]

Pointer to the size in bytes of the output buffer pointed to by *pOutPropertyItem*.

## Return value

If the operations succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following is a possible error code.

| Return code | Description |
| --- | --- |
| **ERROR_BAD_ARGUMENTS** | One or more of the input parameters were invalid. |

## See also

[RESUTIL_PROPERTY_ITEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resutil_property_item)