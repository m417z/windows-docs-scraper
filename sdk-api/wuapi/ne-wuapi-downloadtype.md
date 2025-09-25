## Description

Specifies the type of update download to perform.

## Constants

### `downloadTypeFull`

A full update download.

### `downloadTypeUpdateBootstrapper`

A download containing only the update bootstrapper.

## Remarks

The values from this enumeration are used by methods of the [IUpdateDownloaderEx](https://learn.microsoft.com/windows/win32/api/wuapi/nn-wuapi-iupdatedownloaderex) interface to specify whether a full download should be performed or only the update bootstrapper should be downloaded. If a caller chooses to only download the update bootstrapper, they are still expected to perform a full download later before they can install the update.

## See also

[IUpdateDownloaderEx::BeginDownload2](https://learn.microsoft.com/windows/win32/api/wuapi/nf-wuapi-iupdatedownloaderex-begindownload2)

[IUpdateDownloaderEx::Download2](https://learn.microsoft.com/windows/win32/api/wuapi/nf-wuapi-iupdatedownloaderex-download2)