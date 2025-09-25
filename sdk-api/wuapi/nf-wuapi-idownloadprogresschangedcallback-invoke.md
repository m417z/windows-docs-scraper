# IDownloadProgressChangedCallback::Invoke

## Description

Handles the notification of a change in the progress of an asynchronous download that was initiated by calling the [IUpdateDownloader.BeginDownload](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatedownloader-begindownload) method.

## Parameters

### `downloadJob` [in]

An [IDownloadJob](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-idownloadjob) interface that contains download information.

### `callbackArgs` [in]

An [IDownloadProgressChangedCallbackArgs](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-idownloadprogresschangedcallbackargs) interface that contains download progress data.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

## See also

[IDownloadProgressChangedCallback](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-idownloadprogresschangedcallback)

[IUpdateDownloader::BeginDownload](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-idownloadprogresschangedcallback-invoke)