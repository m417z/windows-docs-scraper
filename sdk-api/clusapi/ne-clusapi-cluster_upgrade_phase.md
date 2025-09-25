# CLUSTER_UPGRADE_PHASE enumeration

## Description

Describes the state of a rolling upgrade of the operating system on a cluster. This enumeration is used by the [ClusterUpgradeProgressCallback](https://learn.microsoft.com/windows/desktop/api/clusapi/nc-clusapi-pcluster_upgrade_progress_callback) callback function.

## Constants

### `ClusterUpgradePhaseInitialize:1`

The nodes are being notified that an upgrade has started.

### `ClusterUpgradePhaseValidatingUpgrade:2`

The updated is being validated to determine whether the all of nodes in the cluster can be upgraded.

### `ClusterUpgradePhaseUpgradingComponents:3`

The nodes are being upgraded.

### `ClusterUpgradePhaseInstallingNewComponents:4`

The new resources are being installed.

### `ClusterUpgradePhaseUpgradeComplete:5`

The upgrade is complete.

## See also

[ClusterUpgradeFunctionalLevel](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterupgradefunctionallevel)

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)