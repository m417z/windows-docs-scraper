# IAppxBundleReader::GetBlockMap

## Description

Retrieves a read-only block map object from the bundle.

## Parameters

### `blockMapReader` [out, retval]

Type: **[IAppxBlockMapReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxblockmapreader)****

The object model of the block map of a package in the bundle.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAppxBundleReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxbundlereader)