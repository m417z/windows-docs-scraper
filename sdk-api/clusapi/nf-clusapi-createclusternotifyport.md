# CreateClusterNotifyPort function

## Description

Creates
or modifies a notification port. For information on notification ports, see
[Receiving Cluster Events](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/receiving-cluster-events). The **PCLUSAPI_CREATE_CLUSTER_NOTIFY_PORT** type defines a pointer to this function.

## Parameters

### `hChange` [in]

Handle to a notification port or **INVALID_HANDLE_VALUE**, indicating that a new handle
should be created. If *hChange* is an existing handle, the events specified in
*dwFilter* are added to the notification port.

### `hCluster` [in]

Handle to the [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) to be associated with the
notification port identified by *hChange*, or
**INVALID_HANDLE_VALUE**, indicating that the notification port should not be associated
with a cluster. If *hChange* is not set to
**INVALID_HANDLE_VALUE**, *hCluster* cannot be set to
**INVALID_HANDLE_VALUE**.

### `dwFilter` [in]

Bitmask of flags enumerated from the [CLUSTER_CHANGE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_change)
enumeration that specifies the events that will cause notifications to be stored in the queue. One or more of
the following flags can be set using the OR operator, or you can specify all of the flags by using the value
**CLUSTER_CHANGE_ALL**.

#### CLUSTER_CHANGE_CLUSTER_PROPERTY (0x40000000)

The queue receives a notification when the cluster's properties change.

#### CLUSTER_CHANGE_CLUSTER_RECONNECT (0x00080000)

The queue receives a notification when the connection to the cluster identified by
*hCluster* is reestablished after a brief disconnect. Some events generated
immediately before or after this event may have been lost. You need to close all open connections and
reconnect to receive accurate state information.

#### CLUSTER_CHANGE_CLUSTER_STATE (0x20000000)

The queue receives a notification when the cluster becomes unavailable, meaning that all attempts to
communicate with the cluster fail.

#### CLUSTER_CHANGE_GROUP_ADDED (0x00004000)

The queue receives a notification when a new [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) is
created in the cluster.

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

The queue receives a notification when a network interface is permanently removed from a cluster node.

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

The queue receives a notification when the node's properties change.

#### CLUSTER_CHANGE_NODE_STATE (0x00000001)

The queue receives a notification when a node changes state. For a list of possible node state values, see
[GetClusterNodeState](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusternodestate).

#### CLUSTER_CHANGE_QUORUM_STATE (0x10000000)

This notification is reserved for future use.

#### CLUSTER_CHANGE_REGISTRY_ATTRIBUTES (0x00000020)

The queue receives a notification when a
[cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) key's attributes are changed. The
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

### `dwNotifyKey` [in]

A user-specified value to be associated with retrieving notifications from the notification port. The
*dwNotifyKey* is returned from
[GetClusterNotify](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusternotify) when an event of one of the types
specified in *dwFilter* occurs.

## Return value

If the operation succeeds, the function returns a notification port handle.

If the operation fails, the
function returns **NULL**. For more information about the error, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

For more information on using the
**CreateClusterNotifyPort**,
[GetClusterNotify](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusternotify), and
[RegisterClusterNotify](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-registerclusternotify), functions, see
[Receiving Cluster Events](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/receiving-cluster-events).

#### Examples

See the [Notification Port Example](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/notification-port-example).

## See also

[CLUSTER_CHANGE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_change)

[CloseClusterNotifyPort](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closeclusternotifyport)

[Cluster Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-management-functions)

[GetClusterGroupState](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclustergroupstate)

[GetClusterNetInterfaceState](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusternetinterfacestate)

[GetClusterNetworkState](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusternetworkstate)

[GetClusterNodeState](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusternodestate)

[GetClusterNotify](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusternotify)

[GetClusterResourceState](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterresourcestate)

[RegisterClusterNotify](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-registerclusternotify)