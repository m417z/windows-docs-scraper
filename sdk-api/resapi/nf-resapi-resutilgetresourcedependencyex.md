# ResUtilGetResourceDependencyEx function

## Description

Enumerates the [dependencies](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dependencies) of a specified [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) and returns a handle to a dependency of a specified type. The **PRESUTIL_GET_RESOURCE_DEPENDENCY_EX** type defines a pointer to this function.

## Parameters

### `hSelf` [in]

A handle to the dependent resource.

### `lpszResourceType` [in]

A null-terminated Unicode string that specifies the resource type of the dependency to return.

### `dwDesiredAccess` [in]

The requested access privileges. This might be any combination of **GENERIC_READ** (0x80000000), **GENERIC_ALL** (0x10000000), or **MAXIMUM_ALLOWED** (0x02000000). If this value is zero (0), an undefined error might be returned. Using **GENERIC_ALL** is the same as calling [ResUtilGetResourceDependency](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetresourcedependency).

## Return value

If the operation succeeds,
the function returns a handle to one of the resources on which the resource that is specified by *hSelf* depends. The caller is responsible for closing the handle by calling
the [CloseClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closeclusterresource) function.

If the operation fails, the function returns **NULL**. For more information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## See also

[ResUtilGetResourceDependency](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetresourcedependency)

[Resource Utility Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-utility-functions)