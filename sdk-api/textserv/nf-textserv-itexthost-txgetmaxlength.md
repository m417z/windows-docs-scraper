# ITextHost::TxGetMaxLength

## Description

Gets the text host's maximum allowed length for the text.

## Parameters

### `plength`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The maximum allowed text length, in number of characters. If INFINITE is returned, the text services object can use as much memory as needed to store any specified text.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The return value is **S_OK**.

## Remarks

When this maximum is reached, the text services object should reject any further character insertion and pasted text.
[TxSetText](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-txsettext) however should still accept (and set) text longer than the maximum length. This is because this method is used for binding and is critical to maintaining the integrity of the data to which the control is bound.

This method parallels the [EM_LIMITTEXT](https://learn.microsoft.com/windows/desktop/Controls/em-limittext) message.

If the limit returned is less than the number of characters currently in the text services object, no data is lost. Instead, no edits are allowed to the text
*other* than deletion until the text is reduced to below the limit.

## See also

**Conceptual**

[EM_LIMITTEXT](https://learn.microsoft.com/windows/desktop/Controls/em-limittext)

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

**Reference**

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)