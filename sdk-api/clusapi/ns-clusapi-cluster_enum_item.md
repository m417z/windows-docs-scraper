# CLUSTER_ENUM_ITEM structure

## Description

Contains the properties of a cluster object. This structure is used to enumerate clusters in the [ClusterEnumEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterenumex) and [ClusterNodeEnumEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternodeenumex) functions.

## Members

### `dwVersion`

The version of the **CLUSTER_ENUM_ITEM** structure.

### `dwType`

A bitmask that specifies the type of the cluster object.

### `cbId`

The size, in bytes, of the **lpszId** field.

### `lpszId`

The ID of the cluster.

### `cbName`

The size, in bytes, of the **lpszName** field.

### `lpszName`

The name of the cluster.

## See also

[ClusterEnumEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterenumex)

[ClusterNodeEnumEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternodeenumex)

[Data Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-structures)