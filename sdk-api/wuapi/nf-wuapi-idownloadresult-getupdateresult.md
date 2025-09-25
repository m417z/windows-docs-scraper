# IDownloadResult::GetUpdateResult

## Description

Returns an [IUpdateDownloadResult](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatedownloadresult) interface that contains the download information for a specified update.

## Parameters

### `updateIndex` [in]

The index of the update.

### `retval` [out]

An [IUpdateDownloadResult](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatedownloadresult) interface that contains the results for the specified update.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows

error code.

## See also

[IDownloadResult](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-idownloadresult)