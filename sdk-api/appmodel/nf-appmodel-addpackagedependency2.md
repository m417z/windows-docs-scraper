## Description

Adds a run-time reference for the framework package dependency you created earlier by using the [TryCreatePackageDependency](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-trycreatepackagedependency) method, with the specified options. After this method successfully returns, your app can activate types and use content from the framework package.

## Parameters

### `packageDependencyId`

Type: **PCWSTR**

The ID of the package dependency to be resolved and added to the invoking process' package graph. This parameter must match a package dependency defined by using the [TryCreatePackageDependency](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-trycreatepackagedependency) function for the calling user or the system (via the [CreatePackageDependencyOptions_ScopeIsSystem](https://learn.microsoft.com/windows/win32/api/appmodel/ne-appmodel-createpackagedependencyoptions) option), or else an error is returned.

### `rank`

Type: **INT32**

The rank to use to add the resolved package to the caller's package graph. For more information, see **Remarks**.

### `options`

Type: **[AddPackageDependencyOptions2](https://learn.microsoft.com/windows/win32/api/appmodel/ne-appmodel-addpackagedependencyoptions2)**

The options to apply when adding the package dependency.

### `packageDependencyContext`

Type: **PACKAGEDEPENDENCY_CONTEXT***

The handle of the added package dependency. This handle is valid until it is passed to [RemovePackageDependency](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-removepackagedependency).

### `packageFullName`

Type: **PCWSTR***

When this method returns, contains the address of a pointer to a null-terminated Unicode string that specifies the full name of the package to which the dependency has been resolved. The caller is responsible for freeing this resource once it is no longer needed by calling [HeapFree](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heapfree).

## Return value

Type: **HRESULT**

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function returns an error code. The possible error codes include the following.

| Return code | Description |
|-------------|-------------|
| E_INVALIDARG | The *packageDependencyId* or *packageDependencyContext* parameter is NULL on input. |

## Remarks

See **Remarks** for [AddPackageDependency](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-addpackagedependency).

## See also

* [RemovePackageDependency](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-removepackagedependency)
* [TryCreatePackageDependency](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-trycreatepackagedependency)
* [Use the dynamic dependency API to reference MSIX packages at run time](https://learn.microsoft.com/windows/apps/desktop/modernize/framework-packages/use-the-dynamic-dependency-api)