# IDWriteFontDownloadQueue::RemoveListener

## Description

Unregisters a notification handler that was previously registered using [AddListener](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritefontdownloadqueue-addlistener).

## Parameters

### `token`

Type: **UINT32**

Token value previously returned by [AddListener](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritefontdownloadqueue-addlistener).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFontDownloadQueue](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontdownloadqueue)