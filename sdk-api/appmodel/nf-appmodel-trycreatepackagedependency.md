## Description

Creates an install-time reference for a framework package dependency for the current app, using the specified package family name, minimum version, and additional criteria.

## Parameters

### `user`

Type: **PSID**

The user scope of the package dependency. If NULL, the caller's user context is used. Must be NULL if [CreatePackageDependencyOptions_ScopeIsSystem](https://learn.microsoft.com/windows/win32/api/appmodel/ne-appmodel-createpackagedependencyoptions) is specified.

### `packageFamilyName`

Type: **PCWSTR**

The package family name of the framework package on which to take dependency.

### `minVersion`

Type: **[PACKAGE_VERSION](https://learn.microsoft.com/windows/desktop/api/appmodel/ns-appmodel-package_version)**

The minimum version of the framework package on which to take dependency.

### `packageDependencyProcessorArchitectures`

Type: **[PackageDependencyProcessorArchitectures](https://learn.microsoft.com/windows/win32/api/appmodel/ne-appmodel-packagedependencyprocessorarchitectures)**

The processor architectures of the package dependency.

### `lifetimeKind`

Type: **[PackageDependencyLifetimeKind](https://learn.microsoft.com/windows/win32/api/appmodel/ne-appmodel-packagedependencylifetimekind)**

The type of artifact to use to define the lifetime of the package dependency. For more information, see the remarks.

### `lifetimeArtifact`

Type: **PCWSTR**

The name of the artifact used to define the lifetime of the package dependency. Must be NULL if the *lifetimeKind* parameter is [PackageDependencyLifetimeKind_Process](https://learn.microsoft.com/windows/win32/api/appmodel/ne-appmodel-packagedependencylifetimekind). For more information, see the remarks.

### `options`

Type: **[CreatePackageDependencyOptions](https://learn.microsoft.com/windows/win32/api/appmodel/ne-appmodel-createpackagedependencyoptions)**

The options to apply when creating the package dependency.

### `packageDependencyId`

Type: **PWSTR***

When this method returns, contains the address of a pointer to a null-terminated Unicode string that specifies the ID of the new package dependency. The caller is responsible for freeing this resource once it is no longer needed by calling [HeapFree](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heapfree).

## Return value

Type: **HRESULT**

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function returns an error code. The possible error codes include the following.

| Return code | Description |
|-------------|-------------|
| E_INVALIDARG | The *packageDependencyId* parameter is NULL on input. |

## Remarks

In your app's installer or during the first run of your app, call this method to specify a set of criteria for a framework package you want to use in your app. This informs the OS that your app has a dependency upon a framework package that meets the specified criteria. If one or more framework packages are installed that meet the criteria, Windows will ensure that at least one of these framework packages will remain installed until the install-time reference is deleted. For more information, see [Use the dynamic dependency API to reference MSIX packages at run time](https://learn.microsoft.com/windows/apps/desktop/modernize/framework-packages/use-the-dynamic-dependency-api).

This function fails if the specified dependency criteria cannot be resolved to a specific package. This package resolution check is skipped if [CreatePackageDependencyOptions_DoNotVerifyDependencyResolution](https://learn.microsoft.com/windows/win32/api/appmodel/ne-appmodel-createpackagedependencyoptions) is specified for the *options* parameter. This is useful for installers running as user contexts other than the target user (for example, installers running as LocalSystem).

## See also

[Use the dynamic dependency API to reference MSIX packages at run time](https://learn.microsoft.com/windows/apps/desktop/modernize/framework-packages/use-the-dynamic-dependency-api)