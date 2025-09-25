# ClusterNetInterfaceCloseEnum function

## Description

Closes a network interface enumeration handle.

## Parameters

### `hNetInterfaceEnum` [in]

Handle to the node enumerator to close. This is a handle originally returned by the [ClusterNetInterfaceOpenEnum](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusternetinterfaceopenenum) function.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.
If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).