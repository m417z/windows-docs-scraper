# IAppxFactory::CreatePackageWriter

## Description

Creates a write-only package object to which files can be added.

## Parameters

### `outputStream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

The output stream that receives the serialized package data. The stream must support at least the [Write](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-write) method.

### `settings` [in]

Type: **[APPX_PACKAGE_SETTINGS](https://learn.microsoft.com/windows/desktop/api/appxpackaging/ns-appxpackaging-appx_package_settings)***

The settings for the production of this package.

### `packageWriter` [out, retval]

Type: **[IAppxPackageWriter](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxpackagewriter)****

The package writer created by this method.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The specified **hashMethod** member of the [APPX_PACKAGE_SETTINGS](https://learn.microsoft.com/windows/desktop/api/appxpackaging/ns-appxpackaging-appx_package_settings) structure is not a valid hash algorithm URI. |
| **ERROR_INVALID_PARAMETER** | The specified **hashMethod** member of the [APPX_PACKAGE_SETTINGS](https://learn.microsoft.com/windows/desktop/api/appxpackaging/ns-appxpackaging-appx_package_settings) structure is not a valid hash algorithm URI. |
| **NTE_BAD_ALGID** | The hash value is [SHA1](http://www.w3.org/2000/09/xmldsig). |

## Remarks

The implementation of an [IAppxPackageWriter](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxpackagewriter) is not guaranteed to write data to the output stream before the [Close](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nf-appxpackaging-iappxpackagewriter-close) method is called on the writer object. No other thread should access *outputStream* until the writer returns from its **Close** method.

#### Examples

For an example, see [How to create an app package](https://learn.microsoft.com/windows/desktop/appxpkg/how-to-create-a-package).

## See also

[IAppxFactory](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxfactory)