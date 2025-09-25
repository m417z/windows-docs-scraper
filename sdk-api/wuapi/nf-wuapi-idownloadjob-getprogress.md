# IDownloadJob::GetProgress

## Description

Returns an [IDownloadProgress](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-idownloadprogress) interface that describes the current progress of a download.

## Parameters

### `retval` [out]

An [IDownloadProgress](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-idownloadprogress) interface that describes the current progress of a download.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

## Remarks

You must make repeated calls to **GetProgress** to track the progress of a download. You must do this because
the [IDownloadProgress](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-idownloadprogress) interface is not automatically updated during a download.

## See also

[IDownloadJob](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-idownloadjob)