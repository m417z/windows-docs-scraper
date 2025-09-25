## Description

Removes a resolved package dependency from the current process' package graph (that is, a run-time reference for a framework package dependency that was added by using the [AddPackageDependency](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-addpackagedependency) method).

## Parameters

### `packageDependencyContext`

Type: **PACKAGEDEPENDENCY_CONTEXT**

The handle of the package dependency to remove.

## Return value

Type: **HRESULT**

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function returns an error code. The possible error codes include the following.

| Return code | Description |
|-------------|-------------|
| E_INVALIDARG | The *packageDependencyContext* parameter is NULL on input. |

## Remarks

This function does not unload loaded resources such as DLLs. After removing a package dependency, any files loaded from the package can continue
to be used. Future file resolution will fail to see the removed package dependency.

## See also

[AddPackageDependency](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-addpackagedependency)