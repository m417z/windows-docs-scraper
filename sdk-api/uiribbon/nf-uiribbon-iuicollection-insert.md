# IUICollection::Insert

## Description

Inserts an item into the [IUICollection](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuicollection) at the specified index.

## Parameters

### `index` [in]

Type: **UINT32**

The zero-based index at which *item* is inserted into the [IUICollection](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuicollection).

### `item` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

Pointer to the item that is added to the [IUICollection](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuicollection).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Gallery Sample](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-gallerysample)

[IUICollection](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuicollection)