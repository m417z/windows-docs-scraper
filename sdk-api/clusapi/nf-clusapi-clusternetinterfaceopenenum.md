# ClusterNetInterfaceOpenEnum function

## Description

Opens an
enumerator for iterating through the installed [network interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-interfaces).

## Parameters

### `hCluster` [in]

Handle to a cluster

### `lpszNodeName` [in, optional]

The name of the node.

### `lpszNetworkName` [in, optional]

The name of the network.

## Return value

If the operation succeeds, returns a handle to an
enumerator.

If the operation fails, the function returns **NULL**. For more information about the
error, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.