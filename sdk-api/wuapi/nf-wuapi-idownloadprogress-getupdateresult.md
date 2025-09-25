# IDownloadProgress::GetUpdateResult

## Description

Returns the result of the download of a specified update.

## Parameters

### `updateIndex` [in]

A zero-based index value that specifies an update.

### `retval` [out]

An [IUpdateDownloadResult](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatedownloadresult) interface that contains information about the specified update.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

## See also

[IDownloadProgress](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-idownloadprogress)