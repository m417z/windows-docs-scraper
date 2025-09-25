# CreateClusterNotifyPortV2 function

## Description

Creates
or modifies a notification port. For information about notification ports, see
[Receiving Cluster Events](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/receiving-cluster-events).

## Parameters

### `hChange` [in]

A handle to a notification port or **INVALID_HANDLE_VALUE**, indicating that a new handle
should be created. If the *hChange* parameter is an existing handle, the events that are specified in
the *dwFilter* parameter are added to the notification port.

### `hCluster` [in]

A handle to the [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) to be associated with the
notification port that is identified by the *hChange* parameter or
**INVALID_HANDLE_VALUE**, indicating that the notification port should not be associated
with a cluster. If the *hChange* parameter is not set to
**INVALID_HANDLE_VALUE**, the *hCluster* parameter cannot be set to
**INVALID_HANDLE_VALUE**.

### `Filters` [in]

A pointer to the [NOTIFY_FILTER_AND_TYPE](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-notify_filter_and_type) structure that specifies the type of notifications that the port can accept.

### `dwFilterCount` [in]

The number of filters that are specified by the *Filters* parameter.

### `dwNotifyKey` [in]

A user-specified value to associate with the retrieval of notifications from the notification port. The
*dwNotifyKey* parameter is returned from
[GetClusterNotifyV2](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusternotifyv2) when an event of one of the types
that are specified in *Filters* occurs.

## Return value

If the operation succeeds, the function returns a notification port handle.

If the operation fails, the
function returns **NULL**. For more information about the error, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Failover Cluster Management Function](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-management-functions)