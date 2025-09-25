# IUICollection::Replace

## Description

Replaces an item at the specified index of the [IUICollection](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuicollection) with another item.

## Parameters

### `indexReplaced` [in]

Type: **UINT32**

The zero-based index of *item* to be replaced in the [IUICollection](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuicollection).

### `itemReplaceWith` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

Pointer to the replacement item that is added to the [IUICollection](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuicollection).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Gallery Sample](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-gallerysample)

[IUICollection](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuicollection)