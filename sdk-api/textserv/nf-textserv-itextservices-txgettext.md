# ITextServices::TxGetText

## Description

Returns all of the Unicode plain text in the control as a **BSTR**.

## Parameters

### `pbstrText`

Type: **BSTR
          ***

The Unicode plain text.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the text is successfully returned in the output argument, the return value is **S_OK**.

If the method fails, the return value is one of the following **HRESULT** codes. For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid **BSTR** pointer passed in. |
| **E_OUTOFMEMORY** | Could not allocate memory for copy of the text. |

## Remarks

The host (caller) takes ownership of the returned **BSTR**.

Other ways to retrieve plain text data are to use [WM_GETTEXT](https://learn.microsoft.com/windows/desktop/winmsg/wm-gettext) or the Text Object Model (TOM) [GetText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-gettext) method.

If there is no text in the control, the **BSTR** is allocated and 0x000D is returned in it.

The returned text will *not* necessarily be null-terminated.

## See also

**Conceptual**

[GetText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-gettext)

[ITextServices](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itextservices)

**Other Resources**

**Reference**

[WM_GETTEXT](https://learn.microsoft.com/windows/desktop/winmsg/wm-gettext)

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)