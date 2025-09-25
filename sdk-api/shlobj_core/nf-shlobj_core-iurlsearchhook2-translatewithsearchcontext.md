# IURLSearchHook2::TranslateWithSearchContext

## Description

Called by the browser when the browser cannot determine the protocol of a URL address. This method uses a search context to determine the protocol.

## Parameters

### `pwszSearchURL` [out]

Type: **PWSTR**

The address of a wide character buffer that, on entry, contains the URL address for which the browser is trying to determine the protocol. On exit, this buffer contains the modified URL address if the method was successful.

### `cchBufferSize`

Type: **DWORD**

The size, in characters, of the buffer at *lpwszSearchURL*.

### `pSearchContext` [in, optional]

Type: **[ISearchContext](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-isearchcontext)***

A pointer to an [ISearchContext](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-isearchcontext) object. This parameter can be **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.