# GetClusterNotify function

## Description

Returns information
relating to the next notification event that is stored for a notification port. The **PCLUSAPI_GET_CLUSTER_NOTIFY** type defines a pointer to this function.

## Parameters

### `hChange` [in]

The handle to a notification port that is created with the
[CreateClusterNotifyPort](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createclusternotifyport) function.

### `lpdwNotifyKey` [out]

A pointer to the notification key for the port that is identified by the *hChange* parameter.

### `lpdwFilterType` [out]

A pointer to a flag that indicates the type of returned event. This flag is one of the following values from the
[CLUSTER_CHANGE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_change) enumeration.

#### CLUSTER_CHANGE_CLUSTER_PROPERTY (0x40000000)

The queue receives a notification when the cluster's prioritized list of internal
[networks](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks) changes.

#### CLUSTER_CHANGE_CLUSTER_RECONNECT (0x00080000)

The queue receives a notification when the connection to the cluster identified by the
*hCluster* parameter is reestablished after a brief disconnect. Some events generated
immediately before or after this event might have been lost. You have to close all open connections and
reconnect to receive accurate state information.

#### CLUSTER_CHANGE_CLUSTER_STATE (0x20000000)

The queue receives a notification when the cluster becomes unavailable, meaning that all attempts to
communicate with the cluster fail.

#### CLUSTER_CHANGE_GROUP_ADDED (0x00004000)

The queue receives a notification when a new [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) is created
in the cluster.

#### CLUSTER_CHANGE_GROUP_DELETED (0x00002000)

The queue receives a notification when an existing group is deleted.

#### CLUSTER_CHANGE_GROUP_PROPERTY (0x00008000)

The queue receives a notification when the
[properties](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/group-common-properties) of a group change or when a
[resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) is added or removed from a group.

#### CLUSTER_CHANGE_GROUP_STATE (0x00001000)

The queue receives a notification when a group changes state. For a list of the possible group state
values, see [GetClusterGroupState](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclustergroupstate).

#### CLUSTER_CHANGE_HANDLE_CLOSE (0x80000000)

The queue receives a notification when a handle associated with a
[cluster object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects) is closed.

#### CLUSTER_CHANGE_NETINTERFACE_ADDED (0x04000000)

The queue receives a notification when a new
[network interface](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-interfaces) is added to a cluster
[node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes).

#### CLUSTER_CHANGE_NETINTERFACE_DELETED (0x02000000)

The queue receives a notification when a network interface is permanently removed from a cluster
node.

#### CLUSTER_CHANGE_NETINTERFACE_PROPERTY (0x08000000)

The queue receives a notification when the
[properties](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-interface-common-properties) of an existing network
interface change.

#### CLUSTER_CHANGE_NETINTERFACE_STATE (0x01000000)

The queue receives a notification when a network interface changes state. For a list of the possible
network interface state values, see
[GetClusterNetInterfaceState](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusternetinterfacestate).

#### CLUSTER_CHANGE_NETWORK_ADDED (0x00400000)

The queue receives a notification when a new
[network](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks) is added to the cluster environment.

#### CLUSTER_CHANGE_NETWORK_DELETED (0x00200000)

The queue receives a notification when a network is permanently removed from the cluster environment.

#### CLUSTER_CHANGE_NETWORK_PROPERTY (0x00800000)

The queue receives a notification when the
[properties](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-common-properties) of an existing network
change.

#### CLUSTER_CHANGE_NETWORK_STATE (0x00100000)

The queue receives a notification when a network changes state. For a list of the possible network state
values, see [GetClusterNetworkState](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusternetworkstate).

#### CLUSTER_CHANGE_NODE_ADDED (0x00000004)

The queue receives a notification when a new [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes)
is added to the cluster. A node can be added only when the Cluster service is initially installed on the
node.

#### CLUSTER_CHANGE_NODE_DELETED (0x00000002)

The queue receives a notification when a node is permanently removed from a cluster. A node can be
permanently deleted from an existing cluster with a call to the
[EvictClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-evictclusternode) function.

#### CLUSTER_CHANGE_NODE_PROPERTY (0x00000008)

This notification is reserved for future use.

#### CLUSTER_CHANGE_NODE_STATE (0x00000001)

The queue receives a notification when a node changes state. For a list of possible node state values, see
[GetClusterNodeState](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusternodestate).

#### CLUSTER_CHANGE_QUORUM_STATE (0x10000000)

This notification is reserved for future use.

#### CLUSTER_CHANGE_REGISTRY_ATTRIBUTES (0x00000020)

The queue receives a notification when the attributes of a
[cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) key are changed. The
only currently defined cluster database key attribute is its security descriptor, which can be changed with
[ClusterRegSetKeySecurity](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregsetkeysecurity).

#### CLUSTER_CHANGE_REGISTRY_NAME (0x00000010)

The queue receives a notification when the name of a cluster database key has changed.

#### CLUSTER_CHANGE_REGISTRY_SUBTREE (0x00000080)

Indicates that the other **CLUSTER_CHANGE_REGISTRY** events apply to the entire
cluster database. If this flag is not included, the events apply only to the specified key.

#### CLUSTER_CHANGE_REGISTRY_VALUE (0x00000040)

The queue receives a notification when a value of the specified cluster database key is changed or deleted.
Cluster database values can be changed with the
[ClusterRegSetValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregsetvalue) function and deleted with
the [ClusterRegDeleteValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregdeletevalue) function.

#### CLUSTER_CHANGE_RESOURCE_ADDED (0x00000400)

The queue receives a notification when a new
[resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) is created in the cluster.

#### CLUSTER_CHANGE_RESOURCE_DELETED (0x00000200)

The queue receives a notification when a resource is deleted.

#### CLUSTER_CHANGE_RESOURCE_PROPERTY (0x00000800)

The queue receives a notification when the
[properties](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-common-properties),
[dependencies](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dependencies), or
[possible owner](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/p-gly) nodes of a resource change.

#### CLUSTER_CHANGE_RESOURCE_STATE (0x00000100)

The queue receives a notification when a resource changes state. For a list of the possible resource state
values, see [GetClusterResourceState](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterresourcestate).

#### CLUSTER_CHANGE_RESOURCE_TYPE_ADDED (0x00020000)

The queue receives a notification when a new
[resource type](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-types) is created in the cluster.

#### CLUSTER_CHANGE_RESOURCE_TYPE_DELETED (0x00010000)

The queue receives a notification when an existing resource type is deleted.

#### CLUSTER_CHANGE_RESOURCE_TYPE_PROPERTY (0x00040000)

The queue receives a notification when the
[properties](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-common-properties) of a resource type
change.

### `lpszName` [out]

A pointer to a null-terminated Unicode string containing the name of the
[cluster object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects) that triggered the event. The
following list describes the content of *lpszName* by event type. Note that
**CLUSTER_CHANGE_REGISTRY_SUBTREE** is not included in the table; this event type is
never handled by **GetClusterNotify**.

#### CLUSTER_CHANGE_CLUSTER_PROPERTY (0x40000000)

Name of the changed cluster.

#### CLUSTER_CHANGE_CLUSTER_RECONNECT (0x00080000)

Name of the disconnected cluster.

#### CLUSTER_CHANGE_CLUSTER_STATE (0x20000000)

Name of the changed cluster.

#### CLUSTER_CHANGE_GROUP_ADDED (0x00004000)

New [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) name.

#### CLUSTER_CHANGE_GROUP_DELETED (0x00002000)

Deleted group name.

#### CLUSTER_CHANGE_GROUP_PROPERTY (0x00008000)

Name of the changed group.

#### CLUSTER_CHANGE_GROUP_STATE (0x00001000)

Name of the changed group.

#### CLUSTER_CHANGE_HANDLE_CLOSE (0x80000000)

Name of the object that is being closed.

#### CLUSTER_CHANGE_NODE_ADDED (0x00000004)

Name of new [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes).

#### CLUSTER_CHANGE_NODE_DELETED (0x00000002)

Name of the deleted node.

#### CLUSTER_CHANGE_NODE_PROPERTY (0x00000008)

Name of the changed node.

#### CLUSTER_CHANGE_NODE_STATE (0x00000001)

Name of the changed node.

#### CLUSTER_CHANGE_REGISTRY_ATTRIBUTES (0x00000020)

Relative name of the changed
[cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) key.

#### CLUSTER_CHANGE_REGISTRY_NAME (0x00000010)

Relative name of the changed cluster database key.

#### CLUSTER_CHANGE_REGISTRY_VALUE (0x00000040)

Relative name of the changed cluster database key.

#### CLUSTER_CHANGE_RESOURCE_ADDED (0x00000400)

New [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) name.

#### CLUSTER_CHANGE_RESOURCE_DELETED (0x00000200)

Deleted resource name.

#### CLUSTER_CHANGE_RESOURCE_PROPERTY (0x00000800)

Name of the changed resource.

#### CLUSTER_CHANGE_RESOURCE_STATE (0x00000100)

Name of the changed resource.

#### CLUSTER_CHANGE_RESOURCE_TYPE_ADDED (0x00020000)

Name of new [resource type](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-types).

#### CLUSTER_CHANGE_RESOURCE_TYPE_DELETED (0x00010000)

Name of the deleted resource type.

### `lpcchName` [in, out]

A pointer to the size of the *lpszName* buffer as a count of characters. On input,
specify the maximum number of characters that the buffer can hold, including the terminating
**NULL**. On output, specifies the number of characters in the resulting name, excluding
the terminating **NULL**.

### `dwMilliseconds` [in, optional]

Optional time-out value that specifies how long the caller is willing to wait for the notification.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following are possible
values.

| Return code/value | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE**<br><br>6 | The handle that is represented in the *hChange* parameter is invalid or has been closed by another thread. |
| **WAIT_TIMEOUT**<br><br>258 (0x102) | The call timed out before the notification could be successfully returned. |
| **ERROR_MORE_DATA**<br><br>234 (0xEA) | The buffer pointed to by the *lpszName* parameter is not big enough to hold the result. The *lpcchName* parameter returns the number of characters in the result, excluding the terminating **NULL**. |

## Remarks

Note that the *lpcchName* parameter refers to a count of characters and not a count of
bytes, and that the returned size does not include the terminating **NULL** in the count.
For more information on sizing buffers, see
[Data Size Conventions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-size-conventions).

The notifications are asynchronous, and the state of the cluster at the time that the application processes the
notification can be different than the state of the cluster at the time the notification was generated.

#### Examples

See the [Notification Port Example](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/notification-port-example).

## See also

[CLUSTER_CHANGE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_change)

[CloseClusterNotifyPort](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closeclusternotifyport)

[Cluster Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-management-functions)

[CreateClusterNotifyPort](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createclusternotifyport)

[RegisterClusterNotify](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-registerclusternotify)