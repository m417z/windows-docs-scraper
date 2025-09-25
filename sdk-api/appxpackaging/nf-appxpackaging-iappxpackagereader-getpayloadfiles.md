# IAppxPackageReader::GetPayloadFiles

## Description

Retrieves an enumerator that iterates through the payload files in the package.

## Parameters

### `filesEnumerator` [out, retval]

Type: **[IAppxFilesEnumerator](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxfilesenumerator)****

 An enumerator over all payload files in the package.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAppxPackageReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxpackagereader)

[IAppxPackageReader::GetFootprintFile](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nf-appxpackaging-iappxpackagereader-getfootprintfile)

[IAppxPackageReader::GetPayloadFile](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nf-appxpackaging-iappxpackagereader-getpayloadfile)