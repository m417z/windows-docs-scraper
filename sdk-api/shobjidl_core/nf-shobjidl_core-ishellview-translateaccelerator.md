# IShellView::TranslateAccelerator

## Description

Translates keyboard shortcut (accelerator) key strokes when a namespace extension's view has the focus.

## Parameters

### `pmsg`

Type: **LPMSG**

The address of the message to be translated.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM-defined error value otherwise.

If the view returns S_OK, it indicates that the message was translated and should not be translated or dispatched by Windows Explorer.

## Remarks

This method is called by Windows Explorer to let the view translate its keyboard shortcuts.

### Notes to Calling Applications

Windows Explorer calls this method before any other translation if the view has the focus. If the view does not have the focus, it is called after Windows Explorer translates its own keyboard shortcuts.

### Notes to Implementers

By default, the view should return S_FALSE so that Windows Explorer can either do its own keyboard shortcut translation or normal menu dispatching. The view should return S_OK only if it has processed the message as the keyboard shortcut and does not want Windows Explorer to process it further.

## See also

[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)