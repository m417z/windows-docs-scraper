# IPreviewHandler::TranslateAccelerator

## Description

Directs the preview handler to handle a keystroke passed up from the message pump of the process in which the preview handler is running.

## Parameters

### `pmsg` [in]

Type: **[MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg)***

A pointer to a window message.

## Return value

Type: **HRESULT**

If the keystroke message can be processed by the preview handler, the handler will process it and return **S_OK**. If the preview handler cannot process the keystroke message, it will offer it to the host using [TranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipreviewhandlerframe-translateaccelerator). If the host processes the message, this method will return **S_OK**. If the host does not process the message, this method will return **S_FALSE**.

## Remarks

This function will only be called from the message pump of the process in which the preview handler is running. This function allows forwarding keystroke messages from the message pump to the host using [TranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipreviewhandlerframe-translateaccelerator).

When the preview handler receives a message (a keystroke) from its message pump, it is responsible for forwarding it to its host.

When [IObjectWithSite::SetSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iobjectwithsite-setsite) is called on the preview handler, a reference to the preview handler's host is passed in. The object should immediately [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) that site for [IPreviewHandlerFrame](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipreviewhandlerframe), and store that pointer.

The preview handler then has the option to call [GetWindowContext](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipreviewhandlerframe-getwindowcontext) to get an accelerator table to filter keystrokes. The preview can then compare keystrokes against that accelerator table using [IsAccelerator](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-isaccelerator) and only call **IPreviewHandler::TranslateAccelerator** for keystrokes that match. This can cause a modest performance increase. The preview handler must release the accelerator table using [DestroyAcceleratorTable](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyacceleratortable) function.

It is also acceptable for the preview handler to avoid using the table altogether and call **IPreviewHandler::TranslateAccelerator** for every keystroke. Note that all preview handlers running in low-integrity processes must use this method.

When a tab key is pressed, if a preview handler has more than one tab stop it is responsible for moving keyboard focus within those tab stops. If the current keyboard focus is on one of those tab stops, and advancing the keyboard focus would move it to another previewer tab stop, the previewer should call SetFocus on the next tab stop. Otherwise the tab key should be forwarded to the host to handle tabbing out of the previewer.