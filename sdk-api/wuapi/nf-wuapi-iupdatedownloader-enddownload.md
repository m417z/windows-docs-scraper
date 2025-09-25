# IUpdateDownloader::EndDownload

## Description

Completes an asynchronous download.

## Parameters

### `value` [in]

The [IDownloadJob](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-idownloadjob) interface pointer that [BeginDownload](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatedownloader-begindownload) returns.

### `retval` [out]

An [IDownloadResult](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-idownloadresult) interface that contains result codes for a download.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **WU_E_INVALID_OPERATION** | The computer cannot access the update site. |

## Remarks

This method returns **WU_E_INVALID_OPERATION** if the object that is implementing the interface is locked down.

When you use any asynchronous WUA API in your app, you might need to implement a time-out mechanism. For more info about how to perform asynchronous WUA operations, see [Guidelines for Asynchronous WUA Operations](https://learn.microsoft.com/windows/desktop/Wua_Sdk/guidelines-for-asynchronous-wua-operations).

## See also

[IUpdateDownloader](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatedownloader)