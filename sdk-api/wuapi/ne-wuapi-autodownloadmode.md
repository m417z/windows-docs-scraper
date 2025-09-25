# AutoDownloadMode enumeration

## Description

Defines the types of logic that is used to determine whether Automatic Updates will automatically download an update once it is determined to be applicable for the computer.

## Constants

### `adLetWindowsUpdateDecide:0`

Use the standard logic. The update will be automatically downloaded if it is important, or if it is recommended and Windows Update has been configured to treat recommended updates as important. Otherwise, the update will not be automatically downloaded.

### `adNeverAutoDownload:1`

The update will not be automatically downloaded; it will be downloaded only when the user attempts to install the update, or when a Windows Update Agent (WUA) API caller requests that the update be downloaded by using the [IUpdateDownloader::Download](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatedownloader-download) or [IUpdateDownloader::BeginDownload](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatedownloader-begindownload) methods.

### `adAlwaysAutoDownload:2`

The update will always be automatically downloaded.

## Remarks

If Automatic Updates is disabled, or if Automatic Updates is enabled but set to “Check for updates but let me choose whether to download or install them,” updates will never be automatically downloaded, regardless of the value of an update’s [IUpdate5::AutoDownload](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdate5-get_autodownload) property. In earlier versions of the WUA in which [IUpdate5](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate5) is not available, all updates are processed by using the standard logic.