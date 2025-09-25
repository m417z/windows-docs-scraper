# ResUtilResourcesEqual function

## Description

Tests whether two resource handles represent the same [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources). The **PRESUTIL_RESOURCES_EQUAL** type defines a pointer to this function.

## Parameters

### `hSelf` [in]

Handle to one of the resources.

### `hResource` [in]

Handle to the other resource.

## Return value

If the resources are equal, the function returns **TRUE**.

If the resources are not equal,
the function returns **FALSE**.

## Remarks

The **ResUtilResourcesEqual** utility function compares the two resources by retrieving their names. To retrieve the names, **ResUtilResourcesEqual** passes the [CLUSCTL_RESOURCE_GET_NAME](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-name) control code to the [ClusterResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcecontrol) function. If the names are the same, the resources are equal.

Do not pass LPC and RPC handles in the same function call. If you do, the call will raise an RPC exception and can result in additional destructive effects. For information on how LPC and RPC handles are created, see [Using Object Handles](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/using-object-handles) and [OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster).

## See also

[CLUSCTL_RESOURCE_GET_NAME](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-name)

[ClusterResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcecontrol)