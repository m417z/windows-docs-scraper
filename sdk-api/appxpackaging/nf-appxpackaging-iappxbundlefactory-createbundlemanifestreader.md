# IAppxBundleFactory::CreateBundleManifestReader

## Description

Creates a read-only bundle manifest object from a standalone stream to AppxBundleManifest.xml.

## Parameters

### `inputStream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

The input stream that delivers the manifest XML for reading. The stream must support [Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read), [Seek](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-seek), and [Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-stat). If these methods fail, their error codes might be passed to and returned by this method.

### `manifestReader` [out, retval]

Type: **IAppxBundleManifestReader****

The manifest reader.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **APPX_E_INVALID_MANIFEST** | The *inputStream* does not contain syntactically valid XML for the manifest. |

## See also

[IAppxBundleFactory](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxbundlefactory)