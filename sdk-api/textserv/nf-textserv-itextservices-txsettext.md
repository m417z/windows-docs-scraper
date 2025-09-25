# ITextServices::TxSetText

## Description

Sets all of the text in the control.

## Parameters

### `pszText` [in]

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The string which will replace the current text.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, the return value is **S_OK**.

If the method fails, the return value is the following **HRESULT** code. For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_FAIL** | Text could not be updated. |

## Remarks

This method should be used with care; it essentially reinitializes the text services object with some new data. Any previous data and formatting information will be lost, including undo information.

If previous data has been copied to the clipboard, that data will be rendered completely to the clipboard (through [OleFlushClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleflushclipboard)) before it is discarded.

This method does *not* support **Undo**.

Two alternate approaches to setting text are [WM_SETTEXT](https://learn.microsoft.com/windows/desktop/winmsg/wm-settext) and [SetText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-settext).

## See also

**Conceptual**

[ITextServices](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itextservices)

[OleFlushClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleflushclipboard)

**Other Resources**

**Reference**

[SetText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-settext)

[WM_SETTEXT](https://learn.microsoft.com/windows/desktop/winmsg/wm-settext)

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)