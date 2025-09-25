# ITextHost::OnTxCharFormatChange

## Description

Sets the default character format for the text host.

## Parameters

### `pCF` [in]

Type: **const [CHARFORMAT](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-charformata)***

The new default-character format.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Return S_OK if the method succeeds.

Return one of the following COM error codes if the method fails. For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are not valid. |
| **E_FAIL** | Unspecified error. |

## See also

[CHARFORMAT](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-charformata)

**Conceptual**

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

**Reference**

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)