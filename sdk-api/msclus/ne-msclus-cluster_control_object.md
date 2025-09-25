# CLUSTER_CONTROL_OBJECT enumeration

## Description

The 8-bit object component of a control code that indicates the type of cluster object to which the
control code applies. For more information, see
[Control Code Architecture](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/control-code-architecture).

## Constants

### `CLUS_OBJECT_INVALID:0`

Zero is not a valid object code value.

### `CLUS_OBJECT_RESOURCE`

Object code part of [resource control codes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-control-codes)
that identifies cluster [resources](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) as the target.

### `CLUS_OBJECT_RESOURCE_TYPE`

Object code part of
[resource type control codes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-type-control-codes) that identifies
cluster [resource types](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-types) as the target.

### `CLUS_OBJECT_GROUP`

Object code part of
[group control codes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/group-control-codes) that identifies cluster
[groups](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) as the target.

### `CLUS_OBJECT_NODE`

Object code part of [node control codes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/node-control-codes) that
identifies cluster [nodes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) as the target.

### `CLUS_OBJECT_NETWORK`

Object code part of [network control codes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-control-codes) that
identifies cluster [networks](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks) as the target.

### `CLUS_OBJECT_NETINTERFACE`

Object code part of
[network interface control codes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-interface-control-codes) that
identifies cluster [network interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-interfaces) as the
target.

### `CLUS_OBJECT_CLUSTER`

Object code part of [cluster control codes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-control-codes) that
identifies a [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) as the target.

### `CLUS_OBJECT_GROUPSET`

Object code part of [cluster control codes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-control-codes) that
identifies a groupset as the target.

**Windows Server 2012 R2 and Windows Server 2012:** This constant is not supported prior to Windows Server 2016.

### `CLUS_OBJECT_USER:128`

Object code part of [control codes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/control-codes) that identifies
cluster object types not defined by Windows Clustering.

## See also

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)