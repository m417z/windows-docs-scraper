# RegisterClusterNotify function

## Description

Adds an
event type to the list of events stored for a notification port. The **PCLUSAPI_REGISTER_CLUSTER_NOTIFY** type defines a pointer to this function.

## Parameters

### `hChange` [in]

Handle to a notification port created with the
[CreateClusterNotifyPort](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createclusternotifyport) function.

### `dwFilterType` [in]

Bitmask of flags that describes the event to be added to the set of events currently being monitored by the
notification port. For more information about these event types, see
[CreateClusterNotifyPort](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createclusternotifyport). The
*dwFilterType* parameter can be set to one of the following flags.

#### CLUSTER_CHANGE_CLUSTER_PROPERTY (0x40000000)

The queue receives a notification when the cluster's prioritized list of internal
[networks](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks) changes.

#### CLUSTER_CHANGE_CLUSTER_RECONNECT

The queue receives a notification when the connection to the cluster identified by
*hCluster* is reestablished after a brief disconnect. Some events generated
immediately before or after this event may have been lost. You need to close all open connections and
reconnect to receive accurate state information.

#### CLUSTER_CHANGE_CLUSTER_STATE (0x20000000)

The queue receives a notification when the cluster becomes unavailable, meaning that all attempts to communicate with the cluster fail. This notification is reserved for future use.

#### CLUSTER_CHANGE_GROUP_ADDED (0x00004000)

The queue receives a notification when a new [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) is
created in the cluster.

#### CLUSTER_CHANGE_GROUP_DELETED (0x00002000)

The queue receives a notification when an existing
[group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) is deleted.

#### CLUSTER_CHANGE_GROUP_PROPERTY (0x00008000)

The queue receives a notification when the
[properties](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/group-common-properties) of an existing group change.

#### CLUSTER_CHANGE_GROUP_STATE (0x00001000)

The queue receives a notification when a group changes state.

#### CLUSTER_CHANGE_HANDLE_CLOSE (0x80000000)

The queue receives a notification when a handle to a
[cluster object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects) is closed.

#### CLUSTER_CHANGE_NETINTERFACE_ADDED (0x04000000)

The queue receives a notification when a new
[network interface](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-interfaces) is added to a cluster
[node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes).

#### CLUSTER_CHANGE_NETINTERFACE_DELETED (0x02000000)

The queue receives a notification when a network interface is permanently removed from a cluster node.

#### CLUSTER_CHANGE_NETINTERFACE_PROPERTY (0x08000000)

The queue receives a notification when the
[properties](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-interface-common-properties) of an existing network interface change.

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

The queue receives a notification when the [properties](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-common-properties) of an existing network change.

#### CLUSTER_CHANGE_NETWORK_STATE (0x00100000)

The queue receives a notification when a network changes state. For a list of the possible network state values, see [GetClusterNetworkState](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusternetworkstate).

#### CLUSTER_CHANGE_NODE_ADDED (0x00000004)

The queue receives a notification when a new [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) is added to the cluster. A node can be added only when the Cluster service is initially installed on the node.

#### CLUSTER_CHANGE_NODE_DELETED (0x00000002)

The queue receives a notification when a [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) is permanently removed from a cluster. A node can be permanently deleted from an existing cluster with a call to the [EvictClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-evictclusternode) function.

#### CLUSTER_CHANGE_NODE_PROPERTY (0x00000008)

This notification is reserved for future use.

#### CLUSTER_CHANGE_NODE_STATE (0x00000001)

The queue receives a notification when a node changes state.

#### CLUSTER_CHANGE_QUORUM_STATE (0x10000000)

The queue receives a notification when the [quorum resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/quorum-resource) changes state.

#### CLUSTER_CHANGE_REGISTRY_ATTRIBUTES (0x00000020)

The queue receives a notification when a [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) key's attributes are changed.

#### CLUSTER_CHANGE_REGISTRY_NAME (0x00000010)

The queue receives a notification when a change to a name is made in the cluster database.

#### CLUSTER_CHANGE_REGISTRY_SUBTREE (0x00000080)

Indicates that the other CLUSTER_CHANGE_REGISTRY events apply to the root of the cluster database and to all of the subkeys. If CLUSTER_CHANGE_REGISTRY_SUBTREE is not specified, the notifications apply only to the root.

#### CLUSTER_CHANGE_REGISTRY_VALUE (0x00000040)

The queue receives a notification when a value of the specified cluster database key is changed or deleted.

#### CLUSTER_CHANGE_RESOURCE_ADDED (0x00000400)

The queue receives a notification when a new [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) is created in the cluster.

#### CLUSTER_CHANGE_RESOURCE_DELETED (0x00000200)

The queue receives a notification when a
[resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) is deleted.

#### CLUSTER_CHANGE_RESOURCE_PROPERTY (0x00000800)

Indicates that a notification should be issued when the
[properties](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-common-properties) of a resource change.

#### CLUSTER_CHANGE_RESOURCE_STATE (0x00000100)

The queue receives a notification when a resource changes state.

#### CLUSTER_CHANGE_RESOURCE_TYPE_ADDED (0x00020000)

The queue receives a notification when a new
[resource type](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-types) is created in the cluster.

#### CLUSTER_CHANGE_RESOURCE_TYPE_DELETED (0x00010000)

The queue receives a notification when an existing resource type is deleted.

#### CLUSTER_CHANGE_RESOURCE_TYPE_PROPERTY (0x00040000)

The queue receives a notification when the
[properties](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-common-properties) of a resource type change.

### `hObject` [in]

Handle to the [failover cluster object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects)
affected by the event specified in the *dwFilterType* parameter. The type of handle
depends on the value of *dwFilterType* as described in the following list.

#### CLUSTER_CHANGE_CLUSTER_PROPERTY

**HCLUSTER**

#### CLUSTER_CHANGE_CLUSTER_STATE

**HCLUSTER**

#### CLUSTER_CHANGE_GROUP_DELETED

**HGROUP**

#### CLUSTER_CHANGE_GROUP_PROPERTY

**HGROUP**

#### CLUSTER_CHANGE_GROUP_STATE

**HGROUP**

#### CLUSTER_CHANGE_HANDLE_CLOSE

**HCLUSTER**, if the flag is used by itself; otherwise, the handle that is associated with the flag that **CLUSTER_CHANGE_HANDLE_CLOSE** is combined with becomes the handle type.

For example, if the value of the *dwFilterType* parameter is **CLUSTER_CHANGE_GROUP_PROPERTY** | **CLUSTER_CHANGE_HANDLE_CLOSE**, then the type of handle for the *hObject* parameter becomes **HGROUP**, because the **CLUSTER_CHANGE_GROUP_PROPERTY** flag is associated with the **HGROUP** handle type.

#### CLUSTER_CHANGE_NODE_DELETED

**HNODE**

#### CLUSTER_CHANGE_NODE_PROPERTY

**HNODE**

#### CLUSTER_CHANGE_NODE_STATE

**HNODE**

#### CLUSTER_CHANGE_REGISTRY_ATTRIBUTES

**HKEY**

#### CLUSTER_CHANGE_REGISTRY_NAME

**HKEY**

#### CLUSTER_CHANGE_REGISTRY_SUBTREE

**HKEY**

#### CLUSTER_CHANGE_REGISTRY_VALUE

**HKEY**

#### CLUSTER_CHANGE_RESOURCE_DELETED

**HRESOURCE**

#### CLUSTER_CHANGE_RESOURCE_PROPERTY

**HRESOURCE**

#### CLUSTER_CHANGE_RESOURCE_STATE

**HRESOURCE**

The cluster database functions return a valid cluster database key that can be used to set
*hObject* when *dwFilterType* is set to an event type affecting
the cluster database.

### `dwNotifyKey` [in]

Notification key returned from
[GetClusterNotify](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusternotify) when the requested event
occurs.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The **RegisterClusterNotify** function enables an application that has already created a notification port with [CreateClusterNotifyPort](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createclusternotifyport) to register for an additional event that affects a [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes), [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources), or [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups).

To receive notifications of
[cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) changes, one or more of the
flags applicable to the database must be set in the *dwFilterType* parameter. Applicable
flags start with the prefix CLUSTER_CHANGE_REGISTRY. Making manual changes to the cluster database through the
registry editor, RegEdit.exe, does not generate notifications.

#### Examples

See the [Notification Port Example](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/notification-port-example).

## See also

[CloseClusterNotifyPort](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closeclusternotifyport)

[CreateClusterNotifyPort](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createclusternotifyport)

[GetClusterNotify](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusternotify)