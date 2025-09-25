# IDWriteFontDownloadQueue::GetGenerationCount

## Description

Gets the current generation number of the download queue, which is incremented
every time after a download completes, whether failed or successful. This cookie
value can be compared against cached data to determine if it is stale.

## Return value

Type: **UINT64**

The current generation number of the download queue.

## See also

[IDWriteFontDownloadQueue](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontdownloadqueue)