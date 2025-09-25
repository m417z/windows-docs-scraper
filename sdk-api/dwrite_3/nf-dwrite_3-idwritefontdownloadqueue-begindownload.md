# IDWriteFontDownloadQueue::BeginDownload

## Description

Begins an asynchronous download operation. The download operation executes
in the background until it completes or is cancelled by a [CancelDownload](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritefontdownloadqueue-canceldownload) call.

## Parameters

### `context` [in, optional]

Type: **IUnknown***

Optional context object that is passed back to the
download notification handler's DownloadCompleted method. If the context object
implements IDWriteFontDownloadListener, its DownloadCompleted will be called
when done.

## Return value

Type: **HRESULT**

 Returns S_OK if a download was successfully begun, S_FALSE if the queue was
empty, or a standard HRESULT error code.

## Remarks

BeginDownload removes all download requests from the queue, transferring them
to a background download operation. If any previous downloads are still ongoing
when BeginDownload is called again, the new download does not complete until
the previous downloads have finished.

## See also

[IDWriteFontDownloadQueue](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontdownloadqueue)