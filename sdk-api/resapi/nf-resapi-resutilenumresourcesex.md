# ResUtilEnumResourcesEx function

## Description

Enumerates all of the [resources](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) in a specified
[cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) and initiates a user-defined operation for each
resource. The **PRESUTIL_ENUM_RESOURCES_EX** type defines a pointer to this function.

## Parameters

### `hCluster` [in]

A handle to the cluster that contains the resources to enumerate.

### `hSelf` [in, optional]

An optional handle to a cluster resource. The callback function is not invoked for a resource that is identified by
*hSelf*.

### `lpszResTypeName` [in]

An optional pointer to a name of a [resource type](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-types) that
narrows the scope of resources to enumerate. If *lpszResTypeName* is specified, only
resources of the specified type are enumerated.

### `pResCallBack` [in]

A pointer to a user-defined function that is called for each enumerated resource. This function must
conform to the definition of the
[ResourceCallbackEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-lpresource_callback_ex) callback function. Note
that parameter names are not part of the definition; they have been added here for clarity.

``` syntax
DWORD (*LPRESOURCE_CALLBACK_EX)(
  HCLUSTER hCluster,
  HRESOURCE hSelf,
  HRESOURCE hEnum,
  PVOID pParameter
);
```

#### hCluster

The *hCluster* parameter that is passed to
**ResUtilEnumResourcesEx**.

#### hSelf

The *hSelf* parameter that is passed to
**ResUtilEnumResourcesEx**. Note that the
callback function is never called when *hSelf* and *hEnum*
refer to the same resource.

#### hEnum

A handle to the resource that currently is being enumerated.
**ResUtilEnumResourcesEx** opens and closes
this handle automatically.

#### pParameter

A generic buffer that enables you to pass any kind of data to the callback function.

### `pParameter` [in]

A generic buffer that enables you to pass any kind of data to the callback function.
**ResUtilEnumResourcesEx** does not use this
parameter at all; it merely passes the pointer to the callback function. Whether you can pass
**NULL** for the parameter depends on how the callback function is implemented.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails, the function immediately halts the enumeration and returns the value that is returned by the
callback function.

## Remarks

**ResUtilEnumResourcesEx** is a convenient and
easy-to-use alternative to the
[ClusterResourceEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourceenum) function.

#### Examples

See the example for
[ResUtilEnumResources](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilenumresources).

## See also

[ClusterResourceEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourceenum)

[ResUtilEnumResources](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilenumresources)

[ResourceCallbackEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-lpresource_callback_ex)