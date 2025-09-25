# CreateClusterGroupEx function

## Description

Creates a new cluster group with the options specified in the **CLUSTER_CREATE_GROUP_INFO** structure in a single operation.The **PCLUSAPI_CREATE_CLUSTER_GROUPEX** type defines a pointer to this function.

## Parameters

### `hCluster` [in]

The handle to the cluster in which the group will be created.

### `lpszGroupName` [in]

The name of the new cluster group.

### `pGroupInfo` [in, optional]

The additional information used to create the group.

## Return value

If the operation is successful, the function returns a handle to the newly created group.
If the operation fails, the function returns **NULL**.

## Remarks

The **CLUSTER_CREATE_GROUP_INFO** structure enables additional properties for group creation. Currently, only the group type can be specified, which enables the group type to be set when the group is created.