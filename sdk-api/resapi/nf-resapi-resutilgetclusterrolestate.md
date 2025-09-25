# ResUtilGetClusterRoleState function

## Description

Determines whether or not a specific role has been assigned to a cluster.

## Parameters

### `hCluster` [in]

The handle of the queried cluster.

### `eClusterRole` [in]

The role the cluster was queried about. The possible values for this parameter are enumerators from the [CLUSTER_ROLE](https://learn.microsoft.com/windows/desktop/api/resapi/ne-resapi-cluster_role) enumeration. The following values are valid.

#### ClusterRoleDHCP (0)

This enumerator represents the DHCP Service cluster role.

#### ClusterRoleDTC (1)

This enumerator represents the Distributed Transaction Coordinator cluster role.

#### ClusterRoleFileServer (2)

This enumerator represents the File Share cluster role.

#### ClusterRoleGenericApplication (3)

This enumerator represents the Generic Application cluster role.

#### ClusterRoleGenericScript (4)

This enumerator represents the Generic Script cluster role.

#### ClusterRoleGenericService (5)

This enumerator represents the Generic Service cluster role.

#### ClusterRoleISCSINameServer (6)

This enumerator represents the Microsoft iSNS cluster role.

#### ClusterRoleMSMQ (7)

This enumerator represents the Microsoft Message Queue cluster role.

#### ClusterRoleNFS (8)

This enumerator represents the NFS Share cluster role.

#### ClusterRolePrintServer (9)

This enumerator represents the Print Spooler cluster role.

#### ClusterRoleStandAloneNamespaceServer (10)

This enumerator represents a specialized File Share cluster role.

#### ClusterRoleVolumeShadowCopyServiceTask (11)

This enumerator represents the Volume Shadow Copy Service Task cluster role.

#### ClusterRoleWINS (12)

This enumerator represents the WINS Service cluster role.

## Return value

The possible return values for this function are enumerators from the [CLUSTER_ROLE_STATE](https://learn.microsoft.com/windows/desktop/api/resapi/ne-resapi-cluster_role_state) enumeration. The following values are valid.

| Return code/value | Description |
| --- | --- |
| **ClusterRoleUnknown**<br><br>-1 | It is unknown whether or not the role is clustered. If this value is returned then an error has occurred. For more information call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). |
| **ClusterRoleClustered**<br><br>0 | The role is clustered. |
| **ClusterRoleUnclustered**<br><br>1 | The role is not clustered. |

## See also

[CLUSTER_ROLE](https://learn.microsoft.com/windows/desktop/api/resapi/ne-resapi-cluster_role)

[CLUSTER_ROLE_STATE](https://learn.microsoft.com/windows/desktop/api/resapi/ne-resapi-cluster_role_state)

[Resource Utility Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-utility-functions)