# CLUS_CHARACTERISTICS enumeration

## Description

Enumerates characteristics of resource types and resources.

## Constants

### `CLUS_CHAR_UNKNOWN:0`

Resources of this type have no known characteristics.

### `CLUS_CHAR_QUORUM:0x1`

Resources of this type are capable of being the
[quorum resource type](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/quorum-resource) for a cluster.

### `CLUS_CHAR_DELETE_REQUIRES_ALL_NODES:0x2`

Resources of this type cannot be deleted unless all nodes are active.

### `CLUS_CHAR_LOCAL_QUORUM:0x4`

Not supported.

### `CLUS_CHAR_LOCAL_QUORUM_DEBUG:0x8`

Not supported.

### `CLUS_CHAR_REQUIRES_STATE_CHANGE_REASON:0x10`

The [resource DLL](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dlls) will receive the
[CLUSCTL_RESOURCE_STATE_CHANGE_REASON](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-state-change-reason)
control code.

### `CLUS_CHAR_BROADCAST_DELETE:0x20`

Not supported.

### `CLUS_CHAR_SINGLE_CLUSTER_INSTANCE:0x40`

Only one instance of this resource type is allowed in a cluster.

### `CLUS_CHAR_SINGLE_GROUP_INSTANCE:0x80`

Only one instance of this resource type is allowed in a group.

### `CLUS_CHAR_COEXIST_IN_SHARED_VOLUME_GROUP:0x100`

The resource can be made part of a special group. Protocol version 2.0 servers do not support this value.

### `CLUS_CHAR_PLACEMENT_DATA:0x200`

The resource type can be queried to get more information about how many resources it uses. For example, in the [virtual machine](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/virtual-machine) resource type, information is returned about how much memory is required for the virtual machine to be started.

**Windows Server 2008 R2 and Windows Server 2008:** This enumeration value is not supported before Windows Server 2012.

### `CLUS_CHAR_MONITOR_DETACH:0x400`

The resource can be deleted without being taken offline. Protocol version 2.0 servers do not support this value.

### `CLUS_CHAR_MONITOR_REATTACH:0x800`

This value is reserved for local use and must be ignored by the client. Protocol version 2.0 servers do not support this value.

### `CLUS_CHAR_OPERATION_CONTEXT:0x1000`

This value is reserved for local use and must be ignored by the client. Protocol version 2.0 servers do not support this value.

### `CLUS_CHAR_CLONES:0x2000`

This value is reserved for local use and must be ignored by the client. Protocol version 2.0 servers do not support this value.

### `CLUS_CHAR_NOT_PREEMPTABLE:0x4000`

The resource should not be preempted, even if the whole group is being preempted.

**Windows Server 2008 R2 and Windows Server 2008:** This enumeration value is not supported before Windows Server 2012.

### `CLUS_CHAR_NOTIFY_NEW_OWNER:0x8000`

The resource can receive a new owner.

**Windows Server 2012, Windows Server 2008 R2 and Windows Server 2008:** This enumeration value is not supported before Windows Server 2012 R2.

### `CLUS_CHAR_SUPPORTS_UNMONITORED_STATE:0x10000`

The resource can continue run in an unmonitored state when it losses cluster membership.

**Windows Server 2012 R2, Windows Server 2012, Windows Server 2008 R2 and Windows Server 2008:** This enumeration value is not supported before Windows Server 2016.

### `CLUS_CHAR_INFRASTRUCTURE:0x20000`

This value is reserved for infrastructure.

**Windows Server 2012 R2, Windows Server 2012, Windows Server 2008 R2 and Windows Server 2008:** This enumeration value is not supported before Windows Server 2016.

## See also

[CLUSCTL_GROUP_GET_CHARACTERISTICS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-group-get-characteristics)

[CLUSCTL_NETINTERFACE_GET_CHARACTERISTICS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-netinterface-get-characteristics)

[CLUSCTL_NETWORK_GET_CHARACTERISTICS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-network-get-characteristics)

[CLUSCTL_NODE_GET_CHARACTERISTICS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-node-get-characteristics)

[CLUSCTL_RESOURCE_GET_CHARACTERISTICS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-characteristics)

[CLUSCTL_RESOURCE_TYPE_GET_CHARACTERISTICS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-get-characteristics)

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)