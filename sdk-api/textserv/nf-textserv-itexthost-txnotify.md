# ITextHost::TxNotify

## Description

Notifies the text host of various events.

## Parameters

### `iNotify` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Event to notify host of. One of the
**EN_** notification codes.

### `pv` [in]

Type: **void***

Extra data, dependent on
*iNotify*.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Return S_OK if the method succeeds.

Return S_FALSE if the method fails. For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

## Remarks

Note that there are two basic categories of events,
*direct* and
*delayed* . Direct events are sent immediately because they need some processing, for example, [EN_PROTECTED](https://learn.microsoft.com/windows/desktop/Controls/en-protected). Delayed events are sent after all processing has occurred; the control is thus in a stable state. Examples of delayed notifications are [EN_CHANGE](https://learn.microsoft.com/windows/desktop/Controls/en-change), [EN_ERRSPACE](https://learn.microsoft.com/windows/desktop/Controls/en-errspace), and [EN_SELCHANGE](https://learn.microsoft.com/windows/desktop/Controls/en-selchange).

The notification events are the same as the notification codes sent to the parent window of a rich edit window. The firing of events may be controlled with a mask set through the [EM_SETEVENTMASK](https://learn.microsoft.com/windows/desktop/Controls/em-seteventmask) message.

In general, it is legal to make calls to the text services object while processing this method; however, implementers are cautioned to avoid excessive recursion.

The following is a list of the notifications that may be sent.

| Notification | Meaning |
| --- | --- |
| [EN_CHANGE](https://learn.microsoft.com/windows/desktop/Controls/en-change) | Sent after the system updates the screen, when the user takes an action that may have altered text in the control. |
| [EN_DROPFILES](https://learn.microsoft.com/windows/desktop/Controls/en-dropfiles) | Sent when either a [WM_DROPFILES](https://learn.microsoft.com/windows/desktop/shell/wm-dropfiles) message or an [IDropTarget::DragEnter](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragenter) notification is received. |
| [EN_ERRSPACE](https://learn.microsoft.com/windows/desktop/Controls/en-errspace) | Sent when a control cannot allocate enough memory to meet a specified request. |
| [EN_HSCROLL](https://learn.microsoft.com/windows/desktop/Controls/en-hscroll) | Sent when the user clicks the control's horizontal scroll bar before the screen is updated. |
| [EN_KILLFOCUS](https://learn.microsoft.com/windows/desktop/Controls/en-killfocus) | Sent when the control loses the keyboard focus. |
| [EN_LINK](https://learn.microsoft.com/windows/desktop/Controls/en-link) | Sent when a rich edit control receives various messages, such as mouse click messages, when the mouse pointer is over text that has the CFE_LINK effect. |
| [EN_MAXTEXT](https://learn.microsoft.com/windows/desktop/Controls/en-maxtext) | Sent when the current text insertion has exceeded the maximum number of characters for the control. |
| [EN_OLEOPFAILED](https://learn.microsoft.com/windows/desktop/Controls/en-oleopfailed) | Sent when a user action on an OLE object has failed. |
| [EN_PROTECTED](https://learn.microsoft.com/windows/desktop/Controls/en-protected) | Sent when the user takes an action that changes the protected range of text. |
| [EN_REQUESTRESIZE](https://learn.microsoft.com/windows/desktop/Controls/en-requestresize) | Sent when a rich edit control's contents are different from the control's window size. |
| [EN_SAVECLIPBOARD](https://learn.microsoft.com/windows/desktop/Controls/en-saveclipboard) | Sent when an edit control is being destroyed. The text host should indicate whether [OleFlushClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleflushclipboard) should be called. Data indicating the number of characters and objects to be flushed is sent in the [ENSAVECLIPBOARD](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-ensaveclipboard) data structure. Mask value is nothing. |
| [EN_SELCHANGE](https://learn.microsoft.com/windows/desktop/Controls/en-selchange) | Sent when the current selection has changed. A [SELCHANGE](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-selchange) data structure is also sent, which indicates the new selection range at the type of data the selection is currently over. Controlled through the [ENM_SELCHANGE](https://learn.microsoft.com/windows/desktop/Controls/rich-edit-control-event-mask-flags) mask. |
| [EN_SETFOCUS](https://learn.microsoft.com/windows/desktop/Controls/en-setfocus) | Sent when the edit control receives the keyboard focus. No extra data is sent; there is no mask. |
| [EN_STOPNOUNDO](https://learn.microsoft.com/windows/desktop/Controls/en-stopnoundo) | Sent when an action occurs for which the control cannot allocate enough memory to maintain the undo state. If S_FALSE is returned, the action will be stopped; otherwise, the action will continue. |
| [EN_UPDATE](https://learn.microsoft.com/windows/desktop/Controls/en-update) | Sent before an edit control requests a redraw of altered data or text. No additional data is sent. This event is controlled through the [ENM_UPDATE](https://learn.microsoft.com/windows/desktop/Controls/rich-edit-control-event-mask-flags) mask. **Rich Edit 2.0 and later:** The [ENM_UPDATE](https://learn.microsoft.com/windows/desktop/Controls/rich-edit-control-event-mask-flags) mask is ignored and the [EN_UPDATE](https://learn.microsoft.com/windows/desktop/Controls/en-update) notification code is always sent. However, when Microsoft Rich Edit 3.0 emulates Microsoft Rich Edit 1.0, the **ENM_UPDATE** mask controls this notification. |
| [EN_VSCROLL](https://learn.microsoft.com/windows/desktop/Controls/en-vscroll) | Sent when the user clicks an edit control's vertical scroll bar or when the user scrolls the mouse wheel over the edit control, before the screen is updated. This is controlled through the [ENM_SCROLL](https://learn.microsoft.com/windows/desktop/Controls/rich-edit-control-event-mask-flags) mask; no extra data is sent. |

**Note** The [EN_MSGFILTER](https://learn.microsoft.com/windows/desktop/Controls/en-msgfilter) is not sent to **TxNotify**. To filter window messages, use [TxSendMessage](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-txsendmessage).

## See also

**Conceptual**

[EM_SETEVENTMASK](https://learn.microsoft.com/windows/desktop/Controls/em-seteventmask)

[EN_CHANGE](https://learn.microsoft.com/windows/desktop/Controls/en-change)

[EN_DROPFILES](https://learn.microsoft.com/windows/desktop/Controls/en-dropfiles)

[EN_ERRSPACE](https://learn.microsoft.com/windows/desktop/Controls/en-errspace)

[EN_HSCROLL](https://learn.microsoft.com/windows/desktop/Controls/en-hscroll)

[EN_KILLFOCUS](https://learn.microsoft.com/windows/desktop/Controls/en-killfocus)

[EN_LINK](https://learn.microsoft.com/windows/desktop/Controls/en-link)

[EN_MAXTEXT](https://learn.microsoft.com/windows/desktop/Controls/en-maxtext)

[EN_OLEOPFAILED](https://learn.microsoft.com/windows/desktop/Controls/en-oleopfailed)

[EN_PROTECTED](https://learn.microsoft.com/windows/desktop/Controls/en-protected)

[EN_REQUESTRESIZE](https://learn.microsoft.com/windows/desktop/Controls/en-requestresize)

[EN_SAVECLIPBOARD](https://learn.microsoft.com/windows/desktop/Controls/en-saveclipboard)

[EN_SELCHANGE](https://learn.microsoft.com/windows/desktop/Controls/en-selchange)

[EN_SETFOCUS](https://learn.microsoft.com/windows/desktop/Controls/en-setfocus)

[EN_STOPNOUNDO](https://learn.microsoft.com/windows/desktop/Controls/en-stopnoundo)

[EN_UPDATE](https://learn.microsoft.com/windows/desktop/Controls/en-update)

[EN_VSCROLL](https://learn.microsoft.com/windows/desktop/Controls/en-vscroll)

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

**Reference**

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)