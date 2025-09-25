# IAppxBlockMapFile::GetLocalFileHeaderSize

## Description

Retrieves the size of the zip local file header of the associated zip file item.

## Parameters

### `lfhSize` [out, retval]

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

In a valid app package, *lfhSize* corresponds to the size of the zip local file header of the associated zip file item.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAppxBlockMapFile](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxblockmapfile)