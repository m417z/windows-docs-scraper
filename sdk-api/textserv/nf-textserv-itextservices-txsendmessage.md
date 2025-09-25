# ITextServices::TxSendMessage

## Description

Used by the window host to forward messages sent from its window to the text services object.

## Parameters

### `msg`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The message identifier.

### `wparam`

Type: **[WPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The **WPARAM** from the window's message.

### `lparam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The **LPARAM** from the window's message.

### `plresult`

Type: **[LRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The message's return **LRESULT**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, the return value is **S_OK**.

If the method fails, the return value is one of the following **HRESULT** codes. For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Insufficient memory. NOERROR Message was processed, and some action was taken. |
| **S_FALSE** | Message was not processed. Typically indicates that the caller should process the message itself, potentially by calling [DefWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-defwindowproca). |
| **S_MSG_KEYIGNORED** | Message processed, but no action was taken for the keystroke. |

## Remarks

Note that two return values are passed back from this function. The return value that should be passed back from a window procedure is *plresult*. However, in some cases, the returned **LRESULT** does not contain enough information. For example, to implement moving the cursor around controls, it's useful to know if a keystroke (such as right arrow) was processed but ignored (for example, the caret is already at the rightmost position in the text). In these cases, more information may be returned through the returned **HRESULT**.

[WM_CHAR](https://learn.microsoft.com/windows/desktop/inputdev/wm-char) and [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown) should return the value S_MSG_KEYIGNORED when a key or character is recognized, but has no effect, given the current state. For example, S_MSG_KEYIGNORED should be returned in the following cases:

* Any keystroke that tries to move the insertion point to or beyond the beginning or the end of the document; when it is already at the beginning or end of the document, respectively.
* Any keystroke that tries to move the insertion point to or past the next line when it is already on the last line; or to or before the previous line when it is already on the first line.
* Any insertion of the character from [WM_CHAR](https://learn.microsoft.com/windows/desktop/inputdev/wm-char) that would move the insertion point past the maximum length of the control.

## See also

**Conceptual**

[DefWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-defwindowproca)

[ITextServices](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itextservices)

**Other Resources**

[WM_CHAR](https://learn.microsoft.com/windows/desktop/inputdev/wm-char)

[WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown)

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)