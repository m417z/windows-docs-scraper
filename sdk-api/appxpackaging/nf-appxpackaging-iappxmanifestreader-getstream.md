# IAppxManifestReader::GetStream

## Description

Gets the raw XML parsed and read by the manifest reader.

## Parameters

### `manifestStream` [out, retval]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)****

The read-only stream that represents the XML content of the manifest.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The raw XML stream is the entire source stream, and may contain elements and attributes in other namespaces that are ignored by the manifest reader. For example, the XML stream may have elements in other namespaces that were marked in the **IgnorableNamespaces** attribute in the **Package** element, which were not validated. Therefore, you should consider this XML as untrusted.

It is recommended that you use the packaging API to get information from the manifest, rather than parsing the raw XML.

If you parse the XML, you must include XML data validation and XML security testing.

Call the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method when you have finished using the *manifestStream* object.

## See also

[IAppxManifestReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestreader)