# ITextServices::TxGetBaseLinePos

## Description

Gets the base line position of the first visible line, in pixels, relative to the text services client rectangle. This permits aligning controls on their base lines.

## Parameters

#### - pBaseLinePos

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The base line position of the first visible line.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, the return value is **S_OK**.

If the method fails, the return value is the following **HRESULT** code. For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | Not implemented. |

## See also

[ITextServices](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itextservices)

[Windowless Rich Edit Controls Overview](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)