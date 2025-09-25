# IAppxBundleManifestPackageInfo2::GetIsNonQualifiedResourcePackage

## Description

Determines whether the app package is a non-qualified resource package.

## Parameters

### `isNonQualifiedResourcePackage` [out, retval]

True if the package is a non-qualified resource package, False otherwise.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A non-qualified resource package is a package that contains resources that are not qualified with any language, scale, or other qualifier. An example of this could be a package that contains all music files.

For more information on app resources, see [App resources and the Resource Management System](https://learn.microsoft.com/windows/uwp/app-resources/).

## See also

[IAppxBundleManifestPackageInfo2](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxbundlemanifestpackageinfo2)