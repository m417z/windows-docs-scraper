## Description

Adds a run-time reference for the framework package dependency you created earlier by using the [TryCreatePackageDependency](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-trycreatepackagedependency) method, with the specified options. After this method successfully returns, your app can activate types and use content from the framework package.

Also see [AddPackageDependency2](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-addpackagedependency2).

## Parameters

### `packageDependencyId`

Type: **PCWSTR**

The ID of the package dependency to be resolved and added to the invoking process' package graph. This parameter must match a package dependency defined by using the [TryCreatePackageDependency](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-trycreatepackagedependency) function for the calling user or the system (via the [CreatePackageDependencyOptions_ScopeIsSystem](https://learn.microsoft.com/windows/win32/api/appmodel/ne-appmodel-createpackagedependencyoptions) option), or else an error is returned.

### `rank`

Type: **INT32**

The rank to use to add the resolved package to the caller's package graph. For more information, see the remarks.

### `options`

Type: **[AddPackageDependencyOptions](https://learn.microsoft.com/windows/win32/api/appmodel/ne-appmodel-addpackagedependencyoptions)**

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

Calling this method resolves the framework package dependency to a specific package on the system. It also informs the OS that the framework package is in active use and to handle any version updates in a side-by-side manner (effectively delay uninstalling or otherwise servicing the older version until after your app is done using it). Package resolution is specific to a user and can return different values for different users on a system.

Each successful **AddPackageDependency** call adds the resolved package to the calling process' package graph, even if already present. There is no duplicate detection or filtering applied by the API (that is, multiple references from a package is not harmful). After resolution is complete, the package dependency stays resolved for that user until the last reference across all processes for that user is removed via [RemovePackageDependency](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-removepackagedependency) or the process is terminated.

After this method successfully returns, your app can activate types and use content from the framework package until [RemovePackageDependency](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-removepackagedependency) is called.

If multiple packages are present in the package graph with the same rank as the call to **AddPackageDependency**, the resolved package is (by default) added after others of the same rank. To add a package before others of the same rank, specify [AddPackageDependencyOptions_PrependIfRankCollision](https://learn.microsoft.com/windows/win32/api/appmodel/ne-appmodel-addpackagedependencyoptions) for the *options* parameter.

For more information, see [Use the dynamic dependency API to reference MSIX packages at run time](https://learn.microsoft.com/windows/apps/desktop/modernize/framework-packages/use-the-dynamic-dependency-api).

## See also

* [RemovePackageDependency](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-removepackagedependency)
* [TryCreatePackageDependency](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-trycreatepackagedependency)
* [Use the dynamic dependency API to reference MSIX packages at run time](https://learn.microsoft.com/windows/apps/desktop/modernize/framework-packages/use-the-dynamic-dependency-api)