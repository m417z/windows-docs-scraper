# IDelegateFolder::SetItemAlloc

## Description

Provides the delegate folder an [IMalloc](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imalloc) interface used to allocate and free item IDs.

## Parameters

### `pmalloc` [in, optional]

Type: **[IMalloc](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imalloc)***

A pointer to an [IMalloc](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imalloc) interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.