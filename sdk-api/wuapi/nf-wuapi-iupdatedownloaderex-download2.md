## Description

Starts a synchronous download of the content files that are associated with the updates.

## Parameters

### `downloadType`

A value from the [DownloadType](https://learn.microsoft.com/windows/win32/api/wuapi/ne-wuapi-downloadtype) specifying the type of download to perform, full download or downloading only the update bootstrapper.

> [!NOTE]
> Attempting to download the update bootstrapper for an update that does not contain one will fail with the error code WU_E_NOT_SUPPORTED.

### `retval`

An [IDownloadResult](https://learn.microsoft.com/windows/win32/api/wuapi/nn-wuapi-idownloadresult) interface that contains result codes for the download.

## Return value

An **HRESULT** including one of the following values:

| Value | Description |
|-------|-------------|
| S_OK | Success. |
| WU_E_INVALID_OPERATION | The computer cannot access the update site. |
| WU_E_NO_UPDATE | The Windows Update Agent (WUA) does not have updates in the collection. |
| WU_E_NOT_INITIALIZED | The Windows Update Agent (WUA) is not initialized. |
| WU_E_NOT_SUPPORTED | The update bootstrapper download was attempted on an update that doesn't contain one. |

## Remarks

This method returns **WU_E_INVALID_OPERATION** if the object that is implementing the interface is locked down.

This method returns **WU_E_NO_UPDATE** if the [Updates](https://learn.microsoft.com/windows/win32/api/wuapi/nf-wuapi-iupdatedownloader-get_updates) property of the [IUpdateDownloader](https://learn.microsoft.com/windows/win32/api/wuapi/nn-wuapi-iupdatedownloader) interface is not set. This method also returns **WU_E_NO_UPDATE** if the **Updates** property is set to an empty collection.

This method returns **SUS_E_NOT_INITIALIZED** if the download job does not contain updates.

## See also