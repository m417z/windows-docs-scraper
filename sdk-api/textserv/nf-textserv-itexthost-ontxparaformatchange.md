# ITextHost::OnTxParaFormatChange

## Description

Sets the default paragraph format for the text host.

## Parameters

### `pPF` [in]

Type: **const [PARAFORMAT](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-paraformat)***

The new default paragraph format.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Return S_OK if the method succeeds.

Return one of the following COM error codes if the method fails. For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are not valid. |
| **E_FAIL** | Unspecified error. |

## See also

**Conceptual**

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

[PARAFORMAT](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-paraformat)

**Reference**

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)