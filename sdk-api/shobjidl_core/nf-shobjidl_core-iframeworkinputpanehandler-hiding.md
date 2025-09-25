# IFrameworkInputPaneHandler::Hiding

## Description

Called when the input pane is about to leave the display.

## Parameters

### `fEnsureFocusedElementInView` [in]

Type: **BOOL***

A pointer to a value that is set to **true** if the app should attempt to keep its currently focused element (such as a text box) in view, which could require the app to rearrange its UI or move the element, usually back to its layout before the input pane was shown.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IFrameworkInputPaneHandler](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iframeworkinputpanehandler)