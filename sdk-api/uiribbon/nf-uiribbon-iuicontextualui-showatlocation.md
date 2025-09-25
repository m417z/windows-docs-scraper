# IUIContextualUI::ShowAtLocation

## Description

Displays a [ContextPopup](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-contextpopup).

## Parameters

### `x`

Type: **INT32**

The absolute x-coordinate, in screen coordinates, for the upper-left corner of the [ContextPopup](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-contextpopup).

### `y`

Type: **INT32**

The absolute y-coordinate, in screen coordinates, for the upper-left corner of the [ContextPopup](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-contextpopup).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The location of the [ContextPopup](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-contextpopup) is not based on the screen coordinates of the application window or the mouse pointer.

## See also

[Context Popup](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-controls-contextpopup)

[ContextPopup Sample](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-contextpopupsample)

[IUIContextualUI](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuicontextualui)