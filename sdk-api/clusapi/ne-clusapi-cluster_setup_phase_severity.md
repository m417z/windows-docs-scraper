# CLUSTER_SETUP_PHASE_SEVERITY enumeration

## Description

Describes the severity of the current phase of the cluster setup process. The
[ClusterSetupProgressCallback](https://learn.microsoft.com/windows/desktop/api/clusapi/nc-clusapi-pcluster_setup_progress_callback) function
uses this enumeration.

## Constants

### `ClusterSetupPhaseInformational:1`

This phase of the cluster setup can complete successfully.

### `ClusterSetupPhaseWarning:2`

This phase of the cluster setup can complete, with a warning.

### `ClusterSetupPhaseFatal:3`

This phase of the cluster setup process cannot complete successfully.

## See also

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)

[PCLUSTER_SETUP_PROGRESS_CALLBACK](https://learn.microsoft.com/windows/desktop/api/clusapi/nc-clusapi-pcluster_setup_progress_callback)