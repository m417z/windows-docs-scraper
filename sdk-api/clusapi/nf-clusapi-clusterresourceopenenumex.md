# ClusterResourceOpenEnumEx function

## Description

Opens a handle to a resource enumeration that enables iteration through a resource's dependencies and nodes.

## Parameters

### `hCluster` [in]

A handle to the resource to iterate through.

### `lpszProperties` [in, optional]

A pointer to a list of names of common properties.

### `cbProperties` [in]

The size, in bytes, of the *lpszProperties* parameter.

### `lpszRoProperties` [in, optional]

A pointer to a list of names of read-only common properties.

### `cbRoProperties` [in]

The size, in bytes, of the *lpszRoProperties* parameter.

### `dwFlags` [in]

The index that identifies the next object to enumerate. This parameter should be zero for the first call to **ClusterResourceOpenEnumEx** and then be incremented for subsequent calls.

## Return value

If the operation succeeds, the function returns an enumeration handle.

If the operation fails, the function returns **NULL**. For more information about the
error, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## See also

[Failover Cluster Resource Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-management-functions)