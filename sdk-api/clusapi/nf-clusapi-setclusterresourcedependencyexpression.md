# SetClusterResourceDependencyExpression function

## Description

Specifies the dependency expression to be associated with the resource referred to by
*hResource*. Any existing dependency relationships for the resource will be
overwritten. The **PCLUSAPI_SET_CLUSTER_RESOURCE_DEPENDENCY_EXPRESSION** type defines a pointer to this function.

## Parameters

### `hResource` [in]

Handle to the resource.

### `lpszDependencyExpression` [in]

Address of Unicode string containing the dependency expression.

## Return value

**ERROR_SUCCESS** (0) if successful.

## Remarks

The system only supports groups of **OR** expressions that are combined by using **AND**. The dependency expressions are
described by this BNF grammar.

``` syntax
expression:
      expression_part
    | expression and expression_part

expression_part:
        resource
    | ( or_expression )

or_expression:
        resource
    | or_expression or resource

resource:
    [resourceID]
    | [resourceName]
```

This gives us expressions of the general form:**( [***id***] or [***id***] ... ) and ( [***id***] or [***id***] ... ) and ...**

For example: ([a904e1b7-95dd-47f0-9b2e-f1007d92699b] or [ae6fcf48-c42f-4960-a61a-7f1044067668]) and ([c471abc6-e454-482e-8be4-fae084cf799b] or [de976488-82cb-4950-8ce0-1b45e868e058])

## See also

[Failover Cluster Resource Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-management-functions)

[GetClusterResourceDependencyExpression](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterresourcedependencyexpression)