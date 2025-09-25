# CREATE_CLUSTER_CONFIG structure

## Description

Defines the initial cluster configuration. This structure is passed in the
*pConfig* parameter to the
[CreateCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createcluster) function.

## Members

### `dwVersion`

Version. Set this to **CLUSAPI_VERSION**.

### `lpszClusterName`

Name of the cluster.

### `cNodes`

Count of nodes in the array pointed to by the **ppszNodeNames** member.

### `ppszNodeNames`

Address of array of pointers to strings, each naming a node to be added to the new cluster.

### `cIpEntries`

Count of nodes in the array pointed to by the **pIpEntries** member. If zero (0), no
[IP Address](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ip-address) or
[Network Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-name) resources will be created.

### `pIpEntries`

Address of array of pointers to [CLUSTER_IP_ENTRY](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-cluster_ip_entry)
structures, each naming a node to be added to the new cluster. Each entry will be used to configure a separate
[IP Address](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ip-address) resource, and a
[Network Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-name) resource will be created which
[depends](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dependencies) on all of these
[IP Address](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ip-address) resources in a logical
**OR** manner.

### `fEmptyCluster`

If **TRUE**, then the cluster is to be created without any nodes and the
**cIpEntries** member must be zero (0) and the **pIpEntries**
member must be **NULL**.

If **FALSE**, then the cluster is to be created with at least one node and the
**cIpEntries** member must be one (1) or more, the
**pIpEntries** member must not be **NULL**, the
**cNodes** member must be one (1) or more, the **ppszNodeNames**
member must not be **NULL**, and the **lpszClusterName** member
must not be **NULL**.

### `managementPointType`

A [CLUSTER_MGMT_POINT_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_mgmt_point_type) value that specifies the management point type. If the value of the **fEmptyCluster** member of this structure is TRUE, this member is ignored and the structure is treated as if this member were set to **CLUSTER_MGMT_POINT_TYPE_NONE**. If the **dwVersion** member of this structure is set to a value less than **CLUSAPI_VERSION_WINDOWSBLUE**, the value of this member is ignored and the structure is treated as if this member were set to **CLUSTER_MGMT_POINT_TYPE_CNO**.

**Windows Server 2012, Windows Server 2008 R2 and Windows Server 2008:** This member is not supported before Windows Server 2012 R2.

### `managementPointResType`

## See also

[CLUSTER_IP_ENTRY](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-cluster_ip_entry)

[CreateCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createcluster)

[Utility structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/utility-structures)