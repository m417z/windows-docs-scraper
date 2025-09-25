# DownloadPhase enumeration

## Description

Defines the progress of the download of the current update that is returned by the [CurrentUpdateDownloadPhase](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-idownloadprogress-get_currentupdatedownloadphase) property of the [IDownloadProgress](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-idownloadprogress) interface.

## Constants

### `dphInitializing:1`

Initializing the download of the current update.

### `dphDownloading:2`

Downloading the current update.

### `dphVerifying:3`

Verifying the download of the current update.