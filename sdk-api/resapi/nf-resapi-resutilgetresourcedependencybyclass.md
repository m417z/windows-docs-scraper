# ResUtilGetResourceDependencyByClass function

## Description

Enumerates the [dependencies](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dependencies) of a specified [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) in a specified [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) and returns a handle to a dependency that matches a specified resource class. The **PRESUTIL_GET_RESOURCE_DEPENDENCY_BY_CLASS** type defines a pointer to this function.

## Parameters

### `hCluster` [in]

Handle to the cluster to which the resource belongs.

### `hSelf` [in]

Handle to the dependent resource. This resource depends on one or more resources.

### `prci` [in]

Pointer to a [CLUS_RESOURCE_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clus_resource_class_info) structure describing the resource class of the dependency to return.

### `bRecurse` [in]

Determines the scope of the search. If **TRUE**, the function checks the entire dependency tree under the dependent resource. If **FALSE**, the function checks only the resources on which the dependent resource directly depends.

## Return value

If the operation succeeds,
the function returns a handle to one of the resources on which the resource specified by *hSelf* depends. The caller is responsible for closing the handle by calling [CloseClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closeclusterresource).

If the operation fails, the function returns **NULL**. For more information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

Do not call **ResUtilGetResourceDependencyByClass** from any resource DLL entry point function. **ResUtilGetResourceDependencyByClass** can safely be called from a worker thread. For more information, see [Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

#### Examples

As the following example illustrates, if you know that resource A depends on a [storage class resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/s-gly), you can use **ResUtilGetResourceDependencyByClass** to obtain a handle to the storage class resource without knowing anything else about it.

```cpp
// String initialization and error checking omitted.

HCLUSTER hCluster = OpenCluster( lpszClusterName );

//
// Resource A depends on a storage class resource.
// Get a handle to that resource.
//
HRESOURCE hResA = OpenClusterResource( hCluster, lpszResName );

PCLUS_RESOURCE_CLASS_INFO pClassInfo;

pClassInfo->rc = CLUS_RESCLASS_STORAGE;

//
// Returns a handle to the storage class resource on which resource A depends.
// Can now perform a variety of operations on the dependency.
//
HRESOURCE hResD = ResUtilGetResourceDependencyByClass(
                        hCluster,
                        hResA,
                        pClassInfo,
                        TRUE );

// Close handles and free memory.

```

## See also

[CloseClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closeclusterresource)

[ResUtilFindDependentDiskResourceDriveLetter](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilfinddependentdiskresourcedriveletter)

[ResUtilGetResourceDependency](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetresourcedependency)

[ResUtilGetResourceDependencyByName](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetresourcedependencybyname)

[ResUtilGetResourceDependentIPAddressProps](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetresourcedependentipaddressprops)

[ResUtilGetResourceNameDependency](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetresourcenamedependency)