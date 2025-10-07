# IAppxBundleManifestReader::GetPackageInfoItems

## Description

Retrieves an enumerator over all the \<Package> elements under the \<Packages> element.

## Parameters

### `packageInfoItems` [out, retval]

Type: **IAppxBundleManifestPackageInfoEnumerator****

 An enumerator over all payload packages in a \<Packages> element of a bundle.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAppxBundleManifestReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxbundlemanifestreader)