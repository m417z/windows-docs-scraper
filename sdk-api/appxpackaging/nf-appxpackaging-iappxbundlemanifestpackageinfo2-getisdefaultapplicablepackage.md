# IAppxBundleManifestPackageInfo2::GetIsDefaultApplicablePackage

## Description

Determines whether the app package is a default applicable package.

## Parameters

### `isDefaultApplicablePackage` [out, retval]

True if the package is a default applicable package, False otherwise.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A default applicable package is a package that contains the default MRT-qualified resources. For example, a default applicable package could be English language resources that should be installed by default if no other appropriate alternative language is available.

For more information on app resources, see [App resources and the Resource Management System](https://learn.microsoft.com/windows/uwp/app-resources/).

## See also

[IAppxBundleManifestPackageInfo2](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxbundlemanifestpackageinfo2)