# IFrameworkInputPane::Location

## Description

Gets the current location of the input pane.

## Parameters

### `prcInputPaneScreenLocation` [out]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that, when this method returns successfully, receives the location of the input pane, in screen coordinates. If the input pane is not visible, this structure receives an empty rectangle.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IFrameworkInputPane](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iframeworkinputpane)