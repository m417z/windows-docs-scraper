## Description

Returns the package dependency for the specified context handle.

## Parameters

### `packageDependencyContext`

Type: **PACKAGEDEPENDENCY_CONTEXT**

The handle of the package dependency to return.

### `packageDependencyId`

Type: **PCWSTR***

The ID of the package dependency for the specified context handle. If the package dependency cannot be resolved, the function succeeds but this parameter is **nullptr** on output. Use the [HeapAlloc](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heapalloc) function to allocate memory for this parameter, and use [HeapFree](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heapfree) to deallocate the memory.

## Return value

| Return code | Description |
|-------------|-------------|
| E_INVALIDARG | The *packageDependencyContext* or *packageDependencyId* parameter is NULL on input. |

## Remarks

## See also