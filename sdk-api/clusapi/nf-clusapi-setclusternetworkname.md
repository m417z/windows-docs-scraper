# SetClusterNetworkName function

## Description

Sets the name for a [network](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks). The **PCLUSAPI_SET_CLUSTER_NETWORK_NAME** type defines a pointer to this function.

## Parameters

### `hNetwork` [in]

Handle to a network to name.

### `lpszName` [in]

Pointer to a null-terminated Unicode string containing the new network name.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

**SetClusterNetworkName** changes the [Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks-name) common property of the network identified by *hNetwork*. This is the only way that **Name**, a read-only property, can be changed.

## See also

[Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks-name)

[OpenClusterNetwork](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternetwork)