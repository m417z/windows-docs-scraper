# IPreviewHandlerFrame::TranslateAccelerator

## Description

Directs the host to handle a keyboard shortcut passed from the preview handler.

## Parameters

### `pmsg` [in]

Type: **[MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg)***

A pointer to a [WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command) or [WM_SYSCOMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-syscommand) window message that corresponds to a keyboard shortcut.

## Return value

Type: **HRESULT**

If the keyboard shortcut is one that the host intends to handle, the host will process it and return **S_OK**; otherwise, it returns **S_FALSE**.

## Remarks

**Note** This method is only called by a preview handler in response to an [TranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipreviewhandler-translateaccelerator) call.