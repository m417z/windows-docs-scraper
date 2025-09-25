# IAppxBundleManifestReader::GetStream

## Description

Gets the raw XML document without any preprocessing.

## Parameters

### `manifestStream` [out, retval]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)****

The read-only stream that represents the XML content of the manifest.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The raw XML stream is the entire source stream and might contain elements and attributes in other namespaces that are ignored by the manifest reader. For example, the XML stream might have elements in other namespaces that were marked in the **IgnorableNamespaces** attribute in the **Package** element, which were not validated. So, we recommend not to trust or parse this XML without security testing.

## See also

[IAppxBundleManifestReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxbundlemanifestreader)