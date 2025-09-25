# IDWriteFontDownloadQueue::AddListener

## Description

Registers a client-defined listener object that receives download notifications.
All registered listener's DownloadCompleted will be called after [BeginDownload](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritefontdownloadqueue-begindownload) completes.

## Parameters

### `listener`

Type: **[IDWriteFontDownloadListener](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontdownloadlistener)***

Listener object to add.

### `token` [out]

Type: **UINT32***

Receives a token value, which the caller must subsequently pass to [RemoveListener](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritefontdownloadqueue-removelistener).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An [IDWriteFontDownloadListener](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontdownloadlistener) can also be passed to [BeginDownload](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritefontdownloadqueue-begindownload)
using the context parameter, rather than globally registered to the queue.

## See also

[IDWriteFontDownloadQueue](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontdownloadqueue)