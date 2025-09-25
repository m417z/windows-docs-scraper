# IPreviewHandlerFrame::GetWindowContext

## Description

Gets a list of the keyboard shortcuts for the preview host.

## Parameters

### `pinfo` [out]

Type: **[PREVIEWHANDLERFRAMEINFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-previewhandlerframeinfo)***

A pointer to a [PREVIEWHANDLERFRAMEINFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-previewhandlerframeinfo) structure that receives accelerator table information.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An accelerator table is a list of keyboard shortcuts and the commands that the host should execute. As an optimization, the preview handler can then look at the keystrokes it receives, check them against the accelerator table to see if the host is interested in them, and forward them on if appropriate, ignoring the commands in the structure. The accelerator table returned from **IPreviewHandlerFrame::GetWindowContext**, contains only keystrokes and does not contain valid command entries. Preview handlers can also skip this optimization and simply call [IPreviewHandlerFrame::TranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipreviewhandlerframe-translateaccelerator) for every keystroke. When the preview handler is destroyed, the accelerator table must be freed using the [DestroyAcceleratorTable](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyacceleratortable) function.

This method should be called at the point when the preview handler has called [SetSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iobjectwithsite-setsite) and the results have been cached for later use by the preview handler. This method cannot be called by preview handlers running in low-integrity mode. Those preview handlers must always call [IPreviewHandlerFrame::TranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipreviewhandlerframe-translateaccelerator) for every keystroke.

## See also

[IPreviewHandlerFrame](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipreviewhandlerframe)

[IPreviewHandlerFrame::TranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipreviewhandlerframe-translateaccelerator)