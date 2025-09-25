## Description

Returns the package full name that would be used if the package dependency were to be resolved. This function does not add the package to the invoking process' package graph.

## Parameters

### `packageDependencyId`

Type: **PCWSTR**

The ID of the package dependency to be resolved. This parameter must match a package dependency defined by using the [TryCreatePackageDependency](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-trycreatepackagedependency) function for the calling user or the system (via the [CreatePackageDependencyOptions_ScopeIsSystem](https://learn.microsoft.com/windows/win32/api/appmodel/ne-appmodel-createpackagedependencyoptions) option), or else an error is returned.

### `packageFullName`

Type: **PCWSTR***

The full name of the package to which the dependency has been resolved. If the package dependency cannot be resolved, the function succeeds but this parameter is **nullptr** on output. Use the [HeapAlloc](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heapalloc) function to allocate memory for this parameter, and use [HeapFree](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heapfree) to deallocate the memory.

## Return value

| Return code | Description |
|-------------|-------------|
| E_INVALIDARG | The *packageDependencyId* or *packageFullName* parameter is NULL on input. |

## Remarks

To add the package to the invoking process' package graph, use the [AddPackageDependency](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-addpackagedependency) function.

## See also

[TryCreatePackageDependency](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-trycreatepackagedependency)

[AddPackageDependency](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-addpackagedependency)