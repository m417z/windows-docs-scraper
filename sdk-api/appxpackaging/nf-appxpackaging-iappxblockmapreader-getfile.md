# IAppxBlockMapReader::GetFile

## Description

Retrieves data corresponding to a file in the block map with the specified file name.

## Parameters

### `filename` [in]

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of the file.

### `file` [out, retval]

Type: **[IAppxBlockMapFile](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxblockmapfile)****

The data about the file's attributes and blocks.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)** | The specified file name does not match the name of a file listed in the block map. |

## See also

[IAppxBlockMapReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxblockmapreader)