# ITextHost::TxGetParaFormat

## Description

Requests the text host's default paragraph format.

## Parameters

### `ppPF`

Type: **const [PARAFORMAT](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-paraformat)****

The default paragraph format.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Return S_OK if the method succeeds.

Return the following COM error code if the method fails. For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | Not implemented. |

## Remarks

The host object retains ownership of the [PARAFORMAT](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-paraformat) structure that is returned. However, the pointer returned must remain valid until the host notifies the text services object, through [OnTxPropertyBitsChange](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-ontxpropertybitschange), that the default paragraph format has changed.

## See also

**Conceptual**

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

[OnTxPropertyBitsChange](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-ontxpropertybitschange)

[PARAFORMAT](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-paraformat)

**Reference**

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)