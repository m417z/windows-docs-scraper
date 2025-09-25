# IUpdateDownloader::Download

## Description

Starts a synchronous download of the content files that are associated with the updates.

## Parameters

### `retval` [out]

An [IDownloadResult](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-idownloadresult) interface that contains result codes for the download.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **WU_E_INVALID_OPERATION** | The computer cannot access the update site. |
| **WU_E_NO_UPDATE** | Windows Update Agent (WUA) does not have updates in the collection. |
| **WU_E_NOT_INITIALIZED** | Windows Update Agent is not initialized. |

## Remarks

This method returns **WU_E_INVALID_OPERATION** if the object that is implementing the interface is locked down.

This method returns **WU_E_NO_UPDATE** if the [Updates](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatedownloader-get_updates) property of the [IUpdateDownloader](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatedownloader) interface is not set. This method also returns **WU_E_NO_UPDATE** if the **Updates** property is set to an empty collection.

This method returns **SUS_E_NOT_INITIALIZED** if the download job does not contain updates.

## See also

[IUpdateDownloader](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatedownloader)