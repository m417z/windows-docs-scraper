# OpenCluster function

## Description

Opens a connection to a
[cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) and returns a handle to
it.

## Parameters

### `lpszClusterName` [in, optional]

Specifies one of the following values:

* Pointer to a null-terminated Unicode string containing the name of the cluster or one of the cluster
  [nodes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) expressed as a NetBIOS name, a fully qualified DNS name, or
  an IP address. This produces an RPC cluster handle.
* **NULL**, which produces an LPC handle to the cluster to which the local computer
  belongs.

## Return value

If the operation was successful, **OpenCluster** returns
a cluster handle.

| Return code/value | Description |
| --- | --- |
| **NULL**<br><br>0 | The operation was not successful. For more information about the error, call the function [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). |

## Remarks

A cluster handle is a pointer to an internally defined structure which stores information about the RPC or LPC
connection to the cluster. Any object handles obtained from the cluster handle will be associated with the RPC or
LPC session data stored in the cluster structure. Combining RPC and LPC handles or using handles obtained from
different contexts can cause exceptions or other unpredictable results. For more information, see
[LPC and RPC Handles](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/lpc-and-rpc-handles).

When finished with a cluster handle, it is important to call
[CloseCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closecluster) to ensure that all memory is freed and the
connection is shut down cleanly.

If the cluster is remote, the client must be running a compatible operating system. For example computers running
Windows Server 2008 cannot call **OpenCluster** against a
cluster running Windows Server 2016. To remotely manage these clusters, use
[the Failover Cluster WMI Provider](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/failover-cluster-apis-portal).

#### Examples

See [Using Object Handles](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/using-object-handles).

## See also

[CloseCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closecluster)

[Failover Cluster Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-management-functions)

[OpenClusterEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterex)