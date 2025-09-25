# IUpdateIDList::Update

## Description

Updates the provided child [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) based on the parameters specified by the provided [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx).

## Parameters

### `pbc` [in, optional]

Type: **[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)***

An [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) interface on a bind context object. Used to specify parameters for updating the child [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist). This value can be **NULL**.

### `pidlIn` [in]

Type: **PCUITEMID_CHILD**

The child [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist).

### `ppidlOut` [out]

Type: **PITEMID_CHILD***

A pointer to the child [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) relative to the parent folder.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If *pbc* is **NULL** or does not contain any parameters that apply to the current Shell folder, *ppidlOut* points to the same [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) as *pidlIn*.

## See also

[ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist)

[IUpdateIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iupdateidlist)