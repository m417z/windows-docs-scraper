# ResUtilResourceTypesEqual function

## Description

Tests whether a [resource type](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-types) matches the resource type name of a specified [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources). The **PRESUTIL_RESOURCE_TYPES_EQUAL** type defines a pointer to this function.

## Parameters

### `lpszResourceTypeName` [in]

Pointer to the resource type name to test.

### `hResource` [in]

Handle of the resource to test.

## Return value

If the resource types are equal, the function returns **TRUE**.

If the resource types are not equal,
the function returns **FALSE**.

## Remarks

The **ResUtilResourceTypesEqual** utility function compares the resource type name pointed to by *lpszResourceTypeName* with the resource type name of the resource identified by *hResource*. To perform the comparison, **ResUtilResourceTypesEqual** passes the [CLUSCTL_RESOURCE_GET_RESOURCE_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-resource-type) control code to the [ClusterResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcecontrol) function to retrieve the resource type. If the two resource type names are the same, the resource types are equal. Note that **ResUtilResourceTypesEqual** compares the resource type name and not the resource type [display name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/display-names).

## See also

[CLUSCTL_RESOURCE_GET_RESOURCE_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-resource-type)

[ClusterResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcecontrol)