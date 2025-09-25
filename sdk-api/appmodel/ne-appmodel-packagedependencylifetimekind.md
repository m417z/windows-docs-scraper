## Description

Specifies values that indicate the type of artifact that is used to define the lifetime of a package dependency.

## Constants

### `PackageDependencyLifetimeKind_Process`

The current process is the lifetime artifact. The package dependency is implicitly deleted when the process terminates.

### `PackageDependencyLifetimeKind_FilePath`

The lifetime artifact is an absolute filename or path. The package dependency is implicitly deleted when this is deleted.

### `PackageDependencyLifetimeKind_RegistryKey`

The lifetime artifact is a registry key in the format *root*\\*subkey*, where *root* is one of the following: HKEY_LOCAL_MACHINE, HKEY_CURRENT_USER, HKEY_CLASSES_ROOT, or HKEY_USERS. The package dependency is implicitly deleted when this is deleted.

## Remarks

## See also

[TryCreatePackageDependency](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-trycreatepackagedependency)