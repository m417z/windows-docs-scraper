# ResUtilIsResourceClassEqual function

## Description

Tests whether the resource class of a specified [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) is equal to a specified resource class. The **PRESUTIL_IS_RESOURCE_CLASS_EQUAL** type defines a pointer to this function.

## Parameters

### `prci` [in]

Pointer to a [CLUS_RESOURCE_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clus_resource_class_info) structure describing the resource class.

### `hResource` [in]

Handle to the resource whose class is to be compared to *prci*.

## Return value

If the resource classes are equal, the function returns **TRUE**.

If the resource classes are not equal,
the function returns **FALSE**.

## See also

[ResUtilResourcesEqual](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilresourcesequal)