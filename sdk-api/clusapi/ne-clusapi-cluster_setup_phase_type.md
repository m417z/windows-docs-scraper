# CLUSTER_SETUP_PHASE_TYPE enumeration

## Description

Describes the progress of the cluster setup process. The
[ClusterSetupProgressCallback](https://learn.microsoft.com/windows/desktop/api/clusapi/nc-clusapi-pcluster_setup_progress_callback) function
uses this enumeration. The values of the
[CLUSTER_SETUP_PHASE](https://learn.microsoft.com/windows/desktop/api/clusapi/ne-clusapi-cluster_setup_phase) enumeration identify the current
phase of the cluster setup process. The values of the
[CLUSTER_SETUP_PHASE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/clusapi/ne-clusapi-cluster_setup_phase_severity) enumeration
describe the severity of the cluster setup process.

## Constants

### `ClusterSetupPhaseStart:1`

Indicates the start of a new setup phase.

### `ClusterSetupPhaseContinue:2`

Indicates the continuation of a setup phase.

### `ClusterSetupPhaseEnd:3`

Indicates the end of a setup phase. Called once at the end of every setup phase.

### `ClusterSetupPhaseReport:4`

## See also

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)

[PCLUSTER_SETUP_PROGRESS_CALLBACK](https://learn.microsoft.com/windows/desktop/api/clusapi/nc-clusapi-pcluster_setup_progress_callback)