# IAppxManifestPackageDependency2::GetMaxMajorVersionTested

## Description

Returns the maximum major version number of the package that is tested to be compatible
with the current package.

## Parameters

### `maxMajorVersionTested` [out]

The maximum major version number of the dependency package that has been tested to be compatible
with the current package.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 If the
**MaxMajorVersionTested** attribute is not specified for the current dependency package, this method returns the highest 16 bits of the **MinVersion** field. For more information, see the [GetMinVersion](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nf-appxpackaging-iappxmanifestpackagedependency-getminversion) method.

## See also

[GetMinVersion](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nf-appxpackaging-iappxmanifestpackagedependency-getminversion)

[IAppxManifestPackageDependency2](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestpackagedependency2)