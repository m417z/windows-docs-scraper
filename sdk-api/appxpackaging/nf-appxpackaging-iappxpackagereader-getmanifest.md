# IAppxPackageReader::GetManifest

## Description

Retrieves the object model of the app manifest of the package.

## Parameters

### `manifestReader` [out, retval]

Type: **[IAppxManifestReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestreader)****

The object model of the app manifest.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The package app manifest is validated when the package reader is created using [IAppxFactory](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxfactory).

#### Examples

For an example, see [Quickstart: Read app package manifest info](https://learn.microsoft.com/windows/desktop/appxpkg/how-to-query-package-identity-information).

## See also

[IAppxPackageReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxpackagereader)