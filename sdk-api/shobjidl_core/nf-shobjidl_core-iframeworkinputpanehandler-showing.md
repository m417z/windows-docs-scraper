# IFrameworkInputPaneHandler::Showing

## Description

Called before the input pane is shown, to allow the app window to make any necessary adjustments to its UI in response to the reduced screen space available to it. This is particularly important for input elements, such as text boxes, that are used in conjunction with the input pane.

## Parameters

### `prcInputPaneScreenLocation` [in]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that supplies the screen coordinates that the input pane will occupy.

### `fEnsureFocusedElementInView` [in]

Type: **BOOL***

A pointer to a value that is set to **true** if the app should attempt to keep its currently focused element (such as a text box) in view, which could require the app to move the element or rearrange its UI.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IFrameworkInputPaneHandler](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iframeworkinputpanehandler)