# IDownloadCompletedCallback::Invoke

## Description

Notifies the caller that the download is complete.

## Parameters

### `downloadJob` [in]

An [IDownloadJob](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-idownloadjob) interface that contains download information.

### `callbackArgs` [in]

This parameter is reserved for future use and can be ignored.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

## See also

[IDownloadCompletedCallback](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-idownloadcompletedcallback)

[IUpdateDownloader::BeginDownload](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatedownloader-begindownload)