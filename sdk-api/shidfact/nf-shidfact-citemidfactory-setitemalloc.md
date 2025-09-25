# CItemIDFactory::SetItemAlloc

## Description

Provides the [CItemIDFactory](https://learn.microsoft.com/windows/desktop/api/shidfact/nl-shidfact-citemidfactory) an [IMalloc](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imalloc) interface used to allocate and free item IDs.

## Parameters

### `pmalloc` [in, out]

A pointer to an [IMalloc](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imalloc) interface.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[CItemIDFactory](https://learn.microsoft.com/windows/desktop/api/shidfact/nl-shidfact-citemidfactory)

[IDelegateFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idelegatefolder)