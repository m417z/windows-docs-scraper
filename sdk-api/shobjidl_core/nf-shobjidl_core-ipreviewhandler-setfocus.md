# IPreviewHandler::SetFocus

## Description

Directs the preview handler to set focus to itself.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method should query the state of the **SHIFT** key to decide whether to set focus to its first tab stop or its last tab stop. This is necessary because the **IPreviewHandler::SetFocus** can only succeed if the focus is being set to a window created by the calling thread.

This is the extent of accelerator keys coming down from the host to the preview handler; no other accelerators are passed down. [IPreviewHandler::TranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipreviewhandler-translateaccelerator) is only used for messages from the preview handler's message pump up to the [IPreviewHandler](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipreviewhandler) object.