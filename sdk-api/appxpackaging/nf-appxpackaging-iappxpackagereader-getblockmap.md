# IAppxPackageReader::GetBlockMap

## Description

Retrieves the block map object model of the package.

## Parameters

### `blockMapReader` [out, retval]

Type: **[IAppxBlockMapReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxblockmapreader)****

The object model of the block map of the package.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The package block map is validated when the package reader is created using [IAppxFactory](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxfactory).

## See also

[IAppxPackageReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxpackagereader)