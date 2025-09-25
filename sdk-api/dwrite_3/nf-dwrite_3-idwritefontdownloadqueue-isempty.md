# IDWriteFontDownloadQueue::IsEmpty

## Description

Determines whether the download queue is empty. Note that the queue does not
include requests that are already being downloaded. Calling [BeginDownload](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritefontdownloadqueue-begindownload) clears the queue.

## Return value

Type: **BOOL**

TRUE if the queue is empty, FALSE if there are requests pending for [BeginDownload](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritefontdownloadqueue-begindownload).

## See also

[IDWriteFontDownloadQueue](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontdownloadqueue)