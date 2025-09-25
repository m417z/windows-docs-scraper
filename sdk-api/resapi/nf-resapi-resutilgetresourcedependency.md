# ResUtilGetResourceDependency function

## Description

Enumerates the [dependencies](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dependencies) of a specified [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) and returns a handle to a dependency of a specified type. The **PRESUTIL_GET_RESOURCE_DEPENDENCY** type defines a pointer to this function.

## Parameters

### `hSelf` [in]

Handle to the dependent resource. This resource depends on one or more resources.

### `lpszResourceType` [in]

Null-terminated Unicode string specifying the resource type of the dependency to return.

## Return value

If the operation succeeds,
the function returns a handle to one of the resources on which the resource specified by *hSelf* depends. The caller is responsible for closing the handle by calling [CloseClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closeclusterresource).

If the operation fails, the function returns **NULL**. For more information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

The **ResUtilGetResourceDependency**, [ResUtilGetResourceDependencyByName](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetresourcedependencybyname), and [ResUtilGetResourceNameDependency](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetresourcenamedependency) functions are very similar in that they all provide access to dependencies of a particular resource type. The following table summarizes the differences between the functions.

| Function | How the dependent resource is specified | Requires cluster handle |
| --- | --- | --- |
| **ResUtilGetResourceDependency** | Resource handle | No |
| [ResUtilGetResourceDependencyByName](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetresourcedependencybyname) | Resource handle | Yes |
| [ResUtilGetResourceNameDependency](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetresourcenamedependency) | Resource name | No |

Do not call **ResUtilGetResourceDependency** from any resource DLL entry point function. **ResUtilGetResourceDependency** can safely be called from a worker thread. For more information, see [Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

#### Examples

As the following example illustrates, if you know that resource A depends on a Physical Disk resource, you can use **ResUtilGetResourceDependency** to obtain a handle to the dependency.

```cpp
// String initialization and error checking omitted.

HCLUSTER hCluster = OpenCluster( lpszClusterName );

//
// Resource A depends on a Physical Disk resource.
// Get a handle to that resource.
//
HRESOURCE hResA = OpenClusterResource( hCluster, lpszResName );

HRESOURCE hResD = ResUtilGetResourceDependency(
                        hResA,
                        L"Physical Disk" );

// Close handles and free memory.

```

## See also

[CloseClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closeclusterresource)

[ResUtilFindDependentDiskResourceDriveLetter](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilfinddependentdiskresourcedriveletter)

[ResUtilGetResourceDependencyByClass](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetresourcedependencybyclass)

[ResUtilGetResourceDependencyByName](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetresourcedependencybyname)

[ResUtilGetResourceDependentIPAddressProps](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetresourcedependentipaddressprops)

[ResUtilGetResourceNameDependency](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetresourcenamedependency)