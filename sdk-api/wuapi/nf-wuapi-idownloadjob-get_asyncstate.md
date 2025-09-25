# IDownloadJob::get_AsyncState

## Description

Gets the caller-specific state object that is passed to the [IUpdateDownloader.BeginDownload](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatedownloader-begindownload) method.

This property is read-only.

## Parameters

## Remarks

This state object can be used by the caller to identify a particular download. Or, this state object can be used by the caller to pass information from the caller to the implementation of the [IDownloadProgressChangedCallback](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-idownloadprogresschangedcallback) or [IDownloadCompletedCallback](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-idownloadcompletedcallback) interface.

## See also

[IDownloadJob](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-idownloadjob)