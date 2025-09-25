# IThumbnailHandlerFactory::GetThumbnailHandler

## Description

Gets the requested thumbnail handler for the thumbnail of a given item.

## Parameters

### `pidlChild` [in]

Type: **PCUITEMID_CHILD**

The item within the namespace for which the thumbnail handler is being retrieved.

### `pbc` [in]

Type: **[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)***

A pointer to an [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) to be used during the moniker binding operation of this process.

### `riid` [in]

Type: **REFIID**

A reference to the IID of the interface requested. This is usually [IThumbnailProvider](https://learn.microsoft.com/windows/desktop/api/thumbcache/nn-thumbcache-ithumbnailprovider) or [IExtractImage](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iextractimage).

### `ppv` [out]

Type: **void****

When this method returns, contains the address of a pointer to the requested thumbnail handler. If this method fails, this value is **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Windows Vista calls the **IThumbnailHandlerFactory::GetThumbnailHandler** method before falling back on [GetUIObjectOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getuiobjectof).