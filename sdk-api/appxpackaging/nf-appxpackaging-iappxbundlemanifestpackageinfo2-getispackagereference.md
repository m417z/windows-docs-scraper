# IAppxBundleManifestPackageInfo2::GetIsPackageReference

## Description

Determines whether a package is stored inside an app bundle, or if it's a reference to a package.

## Parameters

### `isPackageReference` [out, retval]

True if the package in the bundle is a reference to a package; False if the package in the bundle is stored inside the app bundle.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAppxBundleManifestPackageInfo2](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxbundlemanifestpackageinfo2)