# ResUtilGetAllProperties function

## Description

Returns a [property list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-lists) that includes all of the default and [unknown](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/unknown-properties) properties for a [cluster object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects). The **PRESUTIL_GET_ALL_PROPERTIES** type defines a pointer to this function.

## Parameters

### `hkeyClusterKey` [in]

Pointer to the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) key that identifies the location of the properties to retrieve.

### `pPropertyTable` [in]

Pointer to an array of [RESUTIL_PROPERTY_ITEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resutil_property_item) structures that describe the properties to retrieve.

### `pOutPropertyList` [out]

Pointer to an output buffer in which to return the property list.

### `cbOutPropertyListSize` [in]

Size in bytes of the output buffer pointed to by *OutBuffer*.

### `pcbBytesReturned` [out]

Pointer to the total number of bytes in the property list pointed to by *OutBuffer*.

### `pcbRequired` [out]

Pointer to the number of bytes that is required if *OutBuffer* is too small.

## Return value

If the operations succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following are possible error codes.

| Return code | Description |
| --- | --- |
| **ERROR_BAD_ARGUMENTS** | One or more of the input parameters were invalid. |
| **ERROR_NOT_ENOUGH_MEMORY** | There was an error allocating memory. |
| **ERROR_MORE_DATA** | The size of the output buffer is too small to hold the resulting data. The *pcbRequired* parameter points to the correct size. |

## Remarks

The **ResUtilGetAllProperties** utility function makes an entry in the property list for each property that is:

* Included in the [property table](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-tables).
* Included in the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) below the key identified by the *ClusterKey* parameter, regardless of whether the property is included in the property table.

## See also

[RESUTIL_PROPERTY_ITEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resutil_property_item)