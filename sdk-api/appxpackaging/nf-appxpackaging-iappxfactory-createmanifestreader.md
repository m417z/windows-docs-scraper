# IAppxFactory::CreateManifestReader

## Description

Creates a read-only manifest object model from contents provided by an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream).

## Parameters

### `inputStream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

The input stream that delivers the manifest XML for reading. The stream must support [Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read), [Seek](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-seek), and [Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-stat). If these methods fail, their error codes might be passed to and returned by this method.

### `manifestReader` [out, retval]

Type: **[IAppxManifestReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestreader)****

The manifest reader.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **APPX_E_INVALID_MANIFEST** | The *inputStream* does not contain syntactically valid XML for the manifest. |

## Remarks

Use **CreateManifestReader** to read a manifest outside of an app package. This method validates the manifest XML. The *manifestReader* provides access to all data elements and attributes in the manifest XML. The manifest logs the location of manifest validation errors in the ETW event log for AppxPackaging.

#### Examples

For an example, see [Quickstart: Read app package manifest info](https://learn.microsoft.com/windows/desktop/appxpkg/how-to-query-package-identity-information).

## See also

[IAppxFactory](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxfactory)