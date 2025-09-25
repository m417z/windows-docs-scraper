# ResUtilGetPropertySize function

## Description

Returns the total number of bytes required for a specified property.

## Parameters

### `hkeyClusterKey` [in]

[Cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) key identifying the location of the property to size.

### `pPropertyTableItem` [in]

Pointer to a [RESUTIL_PROPERTY_ITEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resutil_property_item) structure describing the property to size.

### `pcbOutPropertyListSize` [in, out]

Pointer to the total number of bytes required for the property value, which includes the [CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) structure and the data.

### `pnPropertyCount` [in, out]

Pointer to the total number of properties. This value is incremented to include this property if **ResUtilGetPropertySize** is successful.

## Return value

If the operations succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following are possible error codes.

| Return code | Description |
| --- | --- |
| **ERROR_BAD_ARGUMENTS** | One or more of the input parameters were invalid. |
| **ERROR_INVALID_PARAMETER** | The data type of a property specified in the property table does not match the data type of the same-named property stored in the cluster database. |

## See also

[CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value)

[RESUTIL_PROPERTY_ITEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resutil_property_item)