# IPreviewHandler::SetRect

## Description

Directs the preview handler to change the area within the parent hwnd that it draws into.

## Parameters

### `prc` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a **RECT** to be used for the preview.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If called before the preview handler window has been created, the new **RECT** replaces the **RECT** previously received in the [IPreviewHandler::SetWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipreviewhandler-setwindow) call.

If called after the preview handler window has been created, the preview handler window must be resized.

If the preview handler is already rendering, then the preview must be resized without interrupting the render process.