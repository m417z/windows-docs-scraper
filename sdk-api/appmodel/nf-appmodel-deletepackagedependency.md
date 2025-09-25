## Description

Deletes the install-time reference for the framework package dependency you created earlier by using the [TryCreatePackageDependency](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-trycreatepackagedependency) method. This method informs the OS that it is safe to remove the framework package if no other apps have a dependency on it.

## Parameters

### `packageDependencyId`

Type: **PCWSTR**

The ID of the package dependency to remove.

## Return value

| Return code | Description |
|-------------|-------------|
| E_INVALIDARG | The *packageDependencyId* parameter is NULL on input. |

## Remarks

Removing a package dependency is typically done when an app is uninstalled. A package dependency is implicitly removed if its lifetime artifact (specified via the *lifetimeArtifact* parameter of the [TryCreatePackageDependency](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-trycreatepackagedependency) function) is deleted. Package dependencies that are not referenced by other packages are elegible to be removed.

The caller of this function must have administrative privileges if the package dependency was created using [CreatePackageDependencyOptions_ScopeIsSystem](https://learn.microsoft.com/windows/win32/api/appmodel/ne-appmodel-createpackagedependencyoptions).

## See also

[TryCreatePackageDependency](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-trycreatepackagedependency)

[Use the dynamic dependency API to reference MSIX packages at run time](https://learn.microsoft.com/windows/apps/desktop/modernize/framework-packages/use-the-dynamic-dependency-api)