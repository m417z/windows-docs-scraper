# ClusterNodeOpenEnumEx function

## Description

Opens an enumerator that can iterate through the network interfaces or groups that are installed on a node.

## Parameters

### `hNode` [in]

A handle to the node.

### `dwType` [in]

A bitmask that describes the type of objects to enumerate. This parameter is retrieved from a
[CLUSTER_NODE_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_node_enum) enumeration value.

### `pOptions` [in, optional] [in, optional]

Options.

## Return value

If the operation succeeds,
the **ClusterNodeOpenEnumEx** function returns a handle to a node
enumerator.

If the operation fails, the function returns **NULL**. For more information about the
error, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## See also

[Node Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/node-management-functions)