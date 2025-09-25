# GetClusterResourceDependencyExpression function

## Description

Retrieves the dependency expression associated with the specified resource. The **PCLUSAPI_GET_CLUSTER_RESOURCE_DEPENDENCY_EXPRESSION** type defines a pointer to this function.

## Parameters

### `hResource` [in]

Handle to the resource.

### `lpszDependencyExpression` [out, optional]

Address of buffer that will receive the dependency expression.

### `lpcchDependencyExpression` [in, out]

Size in characters of the buffer pointed to by the *lpszDependencyExpression*
parameter.

## Return value

**ERROR_SUCCESS** (0) if successful.

## See also

[Failover Cluster Resource Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-management-functions)

[SetClusterResourceDependencyExpression](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-setclusterresourcedependencyexpression)