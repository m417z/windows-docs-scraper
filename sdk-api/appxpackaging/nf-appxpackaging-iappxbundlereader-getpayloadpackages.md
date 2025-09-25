# IAppxBundleReader::GetPayloadPackages

## Description

Retrieves an enumerator that iterates over the list of all payload packages in the bundle.

## Parameters

### `payloadPackages` [out, retval]

Type: **[IAppxFilesEnumerator](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxfilesenumerator)****

 An enumerator over all payload packages in the bundle.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAppxBundleReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxbundlereader)