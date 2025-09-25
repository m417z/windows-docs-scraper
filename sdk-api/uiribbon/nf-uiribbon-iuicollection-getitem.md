# IUICollection::GetItem

## Description

Retrieves an item from the [IUICollection](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuicollection) at the specified index.

## Parameters

### `index` [in]

Type: **UINT32**

The zero-based index of *item* to retrieve from the [IUICollection](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuicollection).

### `item` [out]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)****

When this method returns, contains the address of a pointer variable that receives the item.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Gallery Sample](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-gallerysample)

[IUICollection](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuicollection)