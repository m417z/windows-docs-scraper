# CLUSTER_QUORUM_VALUE enumeration

## Description

Enumerates values returned by the
[ClusterControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clustercontrol) function with the
[CLUSCTL_CLUSTER_CHECK_VOTER_DOWN](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-cluster-check-voter-down) or the
[CLUSCTL_CLUSTER_CHECK_VOTER_EVICT](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-cluster-check-voter-evict)
control codes.

## Constants

### `CLUSTER_QUORUM_MAINTAINED:0`

The quorum will be maintained.

### `CLUSTER_QUORUM_LOST:1`

The quorum will be lost.

## See also

[CLUSCTL_CLUSTER_CHECK_VOTER_DOWN](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-cluster-check-voter-down)

[CLUSCTL_CLUSTER_CHECK_VOTER_EVICT](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-cluster-check-voter-evict)

[ClusterControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clustercontrol)

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)