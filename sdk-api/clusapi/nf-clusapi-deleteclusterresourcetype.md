# DeleteClusterResourceType function

## Description

Removes a [resource type](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-types) from a [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly). The **PCLUSAPI_DELETE_CLUSTER_RESOURCE_TYPE** type defines a pointer to this function.

## Parameters

### `hCluster` [in]

Handle to the cluster containing the resource type to be removed.

### `lpszResourceTypeName` [in]

Pointer to a null-terminated Unicode string containing the name of the resource type to be removed.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The **DeleteClusterResourceType** function only removes the resource type with the name pointed to by *lpszResourceTypeName* from the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) and then unregisters it with the [Cluster service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-service). The caller must delete the [resource DLL](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dlls) for the resource type from each [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) in the cluster.

The caller must also delete any [resources](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) of this type before calling **DeleteClusterResourceType** to delete the type. If any resources of the specified type still exist when **DeleteClusterResourceType** is called, the function fails.

## See also

[CreateClusterResourceType](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createclusterresourcetype)