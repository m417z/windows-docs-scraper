# IUICollectionChangedEvent::OnChanged

## Description

Called when an [IUICollection](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuicollection) changes.

## Parameters

### `action` [in]

Type: **[UI_COLLECTIONCHANGE](https://learn.microsoft.com/windows/desktop/api/uiribbon/ne-uiribbon-ui_collectionchange)**

The [action](https://learn.microsoft.com/windows/desktop/api/uiribbon/ne-uiribbon-ui_collectionchange) performed on the
[IUICollection](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuicollection).

### `oldIndex` [in]

Type: **UINT32**

Index of the old item on remove or replace; otherwise [UI_COLLECTION_INVALIDINDEX](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-ui-collection-invalidindex).

### `oldItem` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

Pointer to the old item on remove or replace; otherwise **NULL**.

### `newIndex` [in]

Type: **UINT32**

Index of the new item on insert, add, or replace; otherwise [UI_COLLECTION_INVALIDINDEX](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-ui-collection-invalidindex).

### `newItem` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

Pointer to the new item on insert, add, or replace; otherwise **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **IUICollectionChangedEvent::OnChanged** interface is implemented by the Ribbon host application
(the client connection sink) as a listener for collection changed
events that are fired by the Ribbon (the connectable object).

## See also

[Events in COM and Connectable Objects](https://learn.microsoft.com/windows/win32/com/events-in-com-and-connectable-objects)

[Gallery Sample](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-gallerysample)

[IUICollection](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuicollection)

[IUICollectionChangedEvent](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuicollectionchangedevent)