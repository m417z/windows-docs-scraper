# ResUtilEnumResourcesEx2 function

## Description

Enumerates all of the [resources](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) in a specified
[cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) and initiates a user-defined operation for each
resource. The **PRESUTIL_ENUM_RESOURCES_EX2** type defines a pointer to this function.

## Parameters

### `hCluster` [in]

A handle to the cluster that contains the resources to enumerate.

### `hSelf` [in, optional]

An optional handle to a cluster resource. The callback function is not invoked for a resource identified by
*hSelf*.

### `lpszResTypeName` [in]

An optional pointer to a name of a [resource type](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-types) that
narrows the scope of resources to enumerate. If *lpszResTypeName* is specified, only
resources of the specified type are enumerated.

### `pResCallBack` [in]

A pointer to a user-defined function which will be called for each enumerated resource. This function must
conform to the definition of the
[ResourceCallbackEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-lpresource_callback_ex) callback function (note
that parameter names are not part of the definition; they have been added here for clarity):

``` syntax
DWORD (*LPRESOURCE_CALLBACK_EX)(
  HCLUSTER hCluster,
  HRESOURCE hSelf,
  HRESOURCE hEnum,
  PVOID pParameter
);
```

#### hCluster

[in] The hCluster parameter passed to
[ResUtilEnumResourcesEx](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilenumresourcesex).

#### hSelf

[in] The hSelf parameter passed to
[ResUtilEnumResourcesEx](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilenumresourcesex). Note that the
callback function is never called when *hSelf* and *hEnum*
refer to the same resource.

#### hEnum

[in] A handle to the resource currently being enumerated.
[ResUtilEnumResourcesEx](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilenumresourcesex) opens and closes
this handle automatically.

#### pParameter

[in] A generic buffer that allows you to pass any kind of data to the callback function.

### `pParameter` [in]

A generic buffer that allows you to pass any kind of data to the callback function.
[ResUtilEnumResourcesEx](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilenumresourcesex) does not use this
parameter at all, it merely passes the pointer to the callback function. Whether or not you can pass
**NULL** for the parameter depends on how the callback function is implemented.

### `dwDesiredAccess` [in]

The requested access privileges. This may be any combination of **GENERIC_READ** (0x80000000), **GENERIC_ALL** (0x10000000), or **MAXIMUM_ALLOWED** (0x02000000). If this value is zero (0), an undefined error may be returned. Using **GENERIC_ALL** is the same as calling [ResUtilEnumResourcesEx](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilenumresourcesex).

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails, the function immediately halts the enumeration and returns the value returned by the
callback function.

## See also

[Resource Utility Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-utility-functions)