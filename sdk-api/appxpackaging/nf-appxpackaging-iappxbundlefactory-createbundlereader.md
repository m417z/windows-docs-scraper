# IAppxBundleFactory::CreateBundleReader

## Description

Creates a read-only bundle object that reads its contents from an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) object.

## Parameters

### `inputStream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

The input stream that delivers the content of the package for reading. The stream must support [Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read), [Seek](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-seek), and [Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-stat). If these methods fail, their error codes might be passed to and returned by this method.

### `bundleReader` [out, retval]

Type: **IAppxBundleReader****

A bundle reader.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **APPX_E_INTERLEAVING_NOT_ALLOWED** | The ZIP file delivered by *inputStream* is an interleaved OPC package. |
| **APPX_E_RELATIONSHIPS_NOT_ALLOWED** | The OPC package delivered by *inputStream* contains OPC package/part relationships. |
| **APPX_E_MISSING_REQUIRED_FILE** | The OPC package delivered by *inputStream* does not have a manifest, or a block map, or a signature file when a CI catalog is present. |
| **APPX_E_INVALID_MANIFEST** | The bundle manifest is not valid. |

## See also

[IAppxBundleFactory](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxbundlefactory)