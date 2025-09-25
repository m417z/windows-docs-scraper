# ClusterSetAccountAccess function

## Description

Updates an account access list (ACL) for a cluster.

## Parameters

### `hCluster` [in]

A handle to the cluster.

### `szAccountSID` [in]

The security identifier (SID) or the account name for the new account access entry (ACE).

### `dwAccess` [in]

The access rights controlled by the ACE.

The possible values are:

#### CLUSAPI_READ_ACCESS (0x00000001L)

Read access.

#### CLUSAPI_CHANGE_ACCESS (0x00000002L)

The account can be used to make changes to the cluster.

#### CLUSAPI_NO_ACCESS (0x00000004L)

No access.

#### CLUSAPI_ALL_ACCESS ((CLUSAPI_READ_ACCESS | CLUSAPI_CHANGE_ACCESS))

The account can be used to read and change the cluster.

### `dwControlType` [in]

The ACE type to use.

The possible values are:

#### CLUSTER_SET_ACCESS_TYPE_ALLOWED (0)

Adds an allowed ACE.

#### CLUSTER_SET_ACCESS_TYPE_DENIED (1)

Adds a denied ACE.

#### CLUSTER_DELETE_ACCESS_CONTROL_ENTRY (2)

Deletes all the ACEs for the SID.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[Cluster Registry Access Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-registry-access-functions)