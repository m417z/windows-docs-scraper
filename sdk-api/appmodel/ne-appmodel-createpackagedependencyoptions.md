## Description

Defines options that can be applied when creating a package dependency by using the [TryCreatePackageDependency](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-trycreatepackagedependency) function.

## Constants

### `CreatePackageDependencyOptions_None`

No options are applied.

### `CreatePackageDependencyOptions_DoNotVerifyDependencyResolution`

Disables dependency resolution when pinning a package dependency. This is useful for installers running as user contexts other than the target user (for example, installers running as LocalSystem).

### `CreatePackageDependencyOptions_ScopeIsSystem`

Defines the package dependency for the system, accessible to all users (by default, the package dependency is defined for a specific user). This option requires the caller has administrative privileges.

## Remarks

## See also

[TryCreatePackageDependency](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-trycreatepackagedependency)