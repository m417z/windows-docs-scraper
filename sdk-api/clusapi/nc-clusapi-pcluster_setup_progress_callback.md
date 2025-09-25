# PCLUSTER_SETUP_PROGRESS_CALLBACK callback function

## Description

Callback function that receives regular updates on the progression of the setup of the
cluster. This callback is used during processing of the
[CreateCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createcluster),
[AddClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-addclusternode), and
[DestroyCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-destroycluster) functions.

## Parameters

### `pvCallbackArg` [in, optional]

*pvCallbackArg* parameter passed to the
[CreateCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createcluster),
[AddClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-addclusternode), or
[DestroyCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-destroycluster) function.

### `eSetupPhase` [in]

Value from the [CLUSTER_SETUP_PHASE](https://learn.microsoft.com/windows/desktop/api/clusapi/ne-clusapi-cluster_setup_phase) enumeration
that gives the current setup phase. The parameter can be one of the following values.

#### ClusterSetupPhaseInitialize (1)

Initialize cluster setup.

#### ClusterSetupPhaseValidateNodeState (100)

Validate cluster nodes.

#### ClusterSetupPhaseValidateNetft (102)

Validate cluster networks.

#### ClusterSetupPhaseValidateClusDisk (103)

Validate cluster disks.

#### ClusterSetupPhaseConfigureClusSvc (104)

Configure cluster service.

#### ClusterSetupPhaseStartingClusSvc (105)

Start cluster service.

#### ClusterSetupPhaseQueryClusterNameAccount (106)

Query cluster name.

#### ClusterSetupPhaseValidateClusterNameAccount (107)

Validate cluster name.

#### ClusterSetupPhaseCreateClusterAccount (108)

Create cluster account.

#### ClusterSetupPhaseConfigureClusterAccount (109)

Configure cluster account.

#### ClusterSetupPhaseFormingCluster (200)

Form the cluster.

#### ClusterSetupPhaseAddClusterProperties (201)

Add properties to cluster.

#### ClusterSetupPhaseCreateResourceTypes (202)

Create resource types.

#### ClusterSetupPhaseCreateGroups (203)

Create resource groups.

#### ClusterSetupPhaseCreateIPAddressResources (204)

Create IP address resources.

#### ClusterSetupPhaseCreateNetworkName (205)

Create network name.

#### ClusterSetupPhaseClusterGroupOnline (206)

Bring cluster groups online.

#### ClusterSetupPhaseGettingCurrentMembership (300)

Get current cluster membership.

#### ClusterSetupPhaseAddNodeToCluster (301)

Add node to cluster membership.

#### ClusterSetupPhaseNodeUp (302)

Start node.

#### ClusterSetupPhaseMoveGroup (400)

Move group to another node.

#### ClusterSetupPhaseDeleteGroup (401)

Delete group from cluster.

#### ClusterSetupPhaseCleanupCOs (402)

Clean up offline group.

#### ClusterSetupPhaseOfflineGroup (403)

Move group offline.

#### ClusterSetupPhaseEvictNode (404)

Remove a node from the cluster.

#### ClusterSetupPhaseCleanupNode (405)

Return node to pre-clustered state.

#### ClusterSetupPhaseCoreGroupCleanup (406)

Return core resource group to pre-clustered state.

#### ClusterSetupPhaseFailureCleanup (999)

Return failed resource to pre-clustered state.

### `ePhaseType` [in]

Value from the [CLUSTER_SETUP_PHASE_TYPE](https://learn.microsoft.com/windows/desktop/api/clusapi/ne-clusapi-cluster_setup_phase_type)
enumeration that gives the current setup phase type. The parameter can be one of the following values.

#### ClusterSetupPhaseStart (1)

Indicates the start of a new setup phase as passed in the *eSetupPhase*
parameter.

#### ClusterSetupPhaseContinue (2)

Indicates the continuation of a setup phase as passed in the *eSetupPhase*
parameter. This callback can be repeated during the processing of the specific setup phase and type.

#### ClusterSetupPhaseEnd (3)

Called once at the end of every setup phase as passed in the *eSetupPhase*
parameter.

### `ePhaseSeverity` [in]

Value from the
[CLUSTER_SETUP_PHASE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/clusapi/ne-clusapi-cluster_setup_phase_severity) enumeration
that gives the current setup phase severity. The parameter can be one of the following values.

#### ClusterSetupPhaseInformational (1)

This phase of the cluster setup can complete successfully.

#### ClusterSetupPhaseWarning (2)

This phase of the cluster setup can complete, with a warning.

#### ClusterSetupPhaseFatal (3)

This phase of the cluster setup process cannot complete successfully.

### `dwPercentComplete` [in]

Indicates approximate percentage of setup that has been completed.

Range: 0–100

### `lpszObjectName` [in, optional]

Name of the object.

### `dwStatus` [in] [in]

Status

## Return value

TBD

## Remarks

The **PCLUSTER_SETUP_PROGRESS_CALLBACK** type defines a pointer to this function.

The [MSCluster_EventClusterCallback](https://learn.microsoft.com/previous-versions/windows/desktop/cluswmi/mscluster-eventclustercallback)
MOF class is used in a similar manner.

## See also

[AddClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-addclusternode)

[CLUSTER_SETUP_PHASE](https://learn.microsoft.com/windows/desktop/api/clusapi/ne-clusapi-cluster_setup_phase)

[CLUSTER_SETUP_PHASE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/clusapi/ne-clusapi-cluster_setup_phase_severity)

[CLUSTER_SETUP_PHASE_TYPE](https://learn.microsoft.com/windows/desktop/api/clusapi/ne-clusapi-cluster_setup_phase_type)

[Cluster Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-management-functions)

[CreateCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createcluster)

[DestroyCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-destroycluster)

[MSCluster_EventClusterCallback](https://learn.microsoft.com/previous-versions/windows/desktop/cluswmi/mscluster-eventclustercallback)