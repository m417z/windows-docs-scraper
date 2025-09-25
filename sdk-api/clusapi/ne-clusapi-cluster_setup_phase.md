# CLUSTER_SETUP_PHASE enumeration

## Description

Used by the
[ClusterSetupProgressCallback](https://learn.microsoft.com/windows/desktop/api/clusapi/nc-clusapi-pcluster_setup_progress_callback) function
to identify the current phase of the cluster setup process.

## Constants

### `ClusterSetupPhaseInitialize:1`

Initialize cluster setup.

### `ClusterSetupPhaseValidateNodeState:100`

Validate cluster nodes.

### `ClusterSetupPhaseValidateNetft:102`

Validate cluster networks.

### `ClusterSetupPhaseValidateClusDisk:103`

Validate cluster disks.

### `ClusterSetupPhaseConfigureClusSvc:104`

Configure cluster service.

### `ClusterSetupPhaseStartingClusSvc:105`

Start cluster service.

### `ClusterSetupPhaseQueryClusterNameAccount:106`

Query cluster name.

### `ClusterSetupPhaseValidateClusterNameAccount:107`

Validate cluster name.

### `ClusterSetupPhaseCreateClusterAccount:108`

Create cluster account.

### `ClusterSetupPhaseConfigureClusterAccount:109`

Configure cluster account.

### `ClusterSetupPhaseFormingCluster:200`

Form the cluster.

### `ClusterSetupPhaseAddClusterProperties:201`

Add properties to cluster.

### `ClusterSetupPhaseCreateResourceTypes:202`

Create resource types.

### `ClusterSetupPhaseCreateGroups:203`

Create resource groups.

### `ClusterSetupPhaseCreateIPAddressResources:204`

Create IP address resources.

### `ClusterSetupPhaseCreateNetworkName:205`

Create network name.

### `ClusterSetupPhaseClusterGroupOnline:206`

Bring cluster groups online.

### `ClusterSetupPhaseGettingCurrentMembership:300`

Get current cluster membership.

### `ClusterSetupPhaseAddNodeToCluster:301`

Add node to cluster membership.

### `ClusterSetupPhaseNodeUp:302`

Start node.

### `ClusterSetupPhaseMoveGroup:400`

Move group to another node.

### `ClusterSetupPhaseDeleteGroup:401`

Delete group from cluster.

### `ClusterSetupPhaseCleanupCOs:402`

Clean up offline group.

### `ClusterSetupPhaseOfflineGroup:403`

Move group offline.

### `ClusterSetupPhaseEvictNode:404`

Remove a node from the cluster.

### `ClusterSetupPhaseCleanupNode:405`

Return node to pre-clustered state.

### `ClusterSetupPhaseCoreGroupCleanup:406`

Return core resource group to pre-clustered state.

### `ClusterSetupPhaseFailureCleanup:999`

Return failed resource to pre-clustered state.

## See also

[ClusterSetupProgressCallback](https://learn.microsoft.com/windows/desktop/api/clusapi/nc-clusapi-pcluster_setup_progress_callback)

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)