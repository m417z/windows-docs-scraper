# CLUSTER_MGMT_POINT_TYPE enumeration

## Description

Specifies the type of the management point for the cluster.

**CLUSTER_MGMT_POINT_TYPE** is used as a possible value in the [CreateCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createcluster) configuration structure.

## Constants

### `CLUSTER_MGMT_POINT_TYPE_NONE:0`

The cluster has no management point.

### `CLUSTER_MGMT_POINT_TYPE_CNO`

The management point is a cluster name object.

### `CLUSTER_MGMT_POINT_TYPE_DNS_ONLY`

The management point is DNS only.

### `CLUSTER_MGMT_POINT_TYPE_CNO_ONLY`

The management point type is cluster name object (CNO) only.

**Windows Server 2012 R2:** This value is not supported before Windows Server 2016.

## See also

[CLUSTER_IP_ENTRY](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-cluster_ip_entry)

[CreateCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createcluster)

[Utility structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/utility-structures)