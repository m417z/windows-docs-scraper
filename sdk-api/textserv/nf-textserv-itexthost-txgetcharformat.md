# ITextHost::TxGetCharFormat

## Description

Requests the text host's default character format.

## Parameters

### `ppCF`

Type: **const [CHARFORMAT](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-charformata)****

The default character format.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Return S_OK if the method succeeds.

Return the following COM error code if the method fails. For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | Not implemented. |

## Remarks

The text host retains ownership of the [CHARFORMAT](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-charformata) returned. However, the pointer returned must remain valid until the text host notifies the text services object through [OnTxPropertyBitsChange](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-ontxpropertybitschange) that the default character format has changed.

## See also

[CHARFORMAT](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-charformata)

**Conceptual**

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

[OnTxPropertyBitsChange](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-ontxpropertybitschange)

**Reference**

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)