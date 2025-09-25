# IDWriteFontDownloadListener::DownloadCompleted

## Description

The DownloadCompleted method is called back on an arbitrary thread when a
download operation ends.

## Parameters

### `downloadQueue` [in]

Type: **[IDWriteFontDownloadQueue](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontdownloadqueue)***

Pointer to the download queue interface on which
the BeginDownload method was called.

### `context` [in, optional]

Type: **IUnknown***

Optional context object that was passed to BeginDownload.
AddRef is called on the context object by BeginDownload and Release is called
after the DownloadCompleted method returns.

### `downloadResult`

Type: **HRESULT**

Result of the download operation.

## See also

[IDWriteFontDownloadListener](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontdownloadlistener)