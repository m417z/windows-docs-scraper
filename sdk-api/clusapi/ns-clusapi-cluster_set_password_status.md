# CLUSTER_SET_PASSWORD_STATUS structure

## Description

Used by the
[SetClusterServiceAccountPassword](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-setclusterserviceaccountpassword)
function to return the results of a [Cluster service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-service) user
account password change for each cluster node.

## Members

### `NodeId`

Identifies the node on which the password change attempt was made.

### `SetAttempted`

If **TRUE**, indicates that the password change was attempted on this node.

### `ReturnStatus`

An error code describing the results of the password change.