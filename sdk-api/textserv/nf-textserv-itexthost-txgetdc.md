# ITextHost::TxGetDC

## Description

Requests the device context for the text host window.

## Return value

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, return the handle of the device context for the client area of the text host window.

If the method fails, return **NULL**. For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

## Remarks

This method is only valid when the control is in-place active; calls while the control is inactive may fail.

## See also

**Conceptual**

[GetDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdc)

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

**Other Resources**

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)