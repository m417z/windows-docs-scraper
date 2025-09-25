# IAppxFactory::CreatePackageReader

## Description

Creates a read-only package reader from the contents provided by an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream). This method does not validate the [digital signature](https://learn.microsoft.com/previous-versions/windows/hh464986(v=win.10)).

## Parameters

### `inputStream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

The input stream that delivers the content of the package for reading. The stream must support [Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read), [Seek](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-seek), and [Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-stat). If these methods fail, their error codes might be passed to and returned by this method.

### `packageReader` [out, retval]

Type: **[IAppxPackageReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxpackagereader)****

A package reader.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **APPX_E_INTERLEAVING_NOT_ALLOWED** | The ZIP file delivered by *inputStream* is an interleaved OPC package. |
| **APPX_E_RELATIONSHIPS_NOT_ALLOWED** | The OPC package delivered by *inputStream* contains OPC package/part relationships. |
| **APPX_E_MISSING_REQUIRED_FILE** | The OPC package delivered by *inputStream* does not have a manifest, or a block map, or a signature file when a CI catalog is present. |
| **APPX_E_INVALID_MANIFEST** | The package manifest is not valid. |
| **APPX_E_INVALID_BLOCKMAP** | The package block map is not valid, the list of files in the ZIP central directory does not match the list of files in the block map, or the size of files listed in the ZIP central directory does not match the file and block sizes listed in the block map. |

## Remarks

The **CreatePackageReader** method immediately retrieves footprint elements of the app package through the stream and validates their content. This method succeeds only if the OPC package and all footprint elements (including ZIP central directory, manifest, [Content_Types].xml, and block map) are valid.

#### Examples

For an example, see [Quickstart: Extract app package contents](https://learn.microsoft.com/windows/desktop/appxpkg/how-to-extract-content-from-a-package) and [Quickstart: Read app package manifest info](https://learn.microsoft.com/windows/desktop/appxpkg/how-to-query-package-identity-information).

## See also

[IAppxFactory](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxfactory)