# IAppxBlockMapFile::GetUncompressedSize

## Description

Retrieves the uncompressed size of the associated zip file item.

## Parameters

### `size` [out, retval]

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

 In a valid app package, *size* is the uncompressed size of the associated zip file item.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAppxBlockMapFile](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxblockmapfile)