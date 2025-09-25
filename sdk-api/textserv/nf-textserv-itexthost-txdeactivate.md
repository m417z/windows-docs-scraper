# ITextHost::TxDeactivate

## Description

Notifies the text host that the control is now inactive.

## Parameters

### `lNewState`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

New state of the control. Typically it is the value returned by [ITextHost::TxActivate](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txactivate).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Return S_OK if the method succeeds.

Return the following COM error code if the method fails. For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_FAIL** | Unspecified error. |

## Remarks

No matter how many times this method is called, only one call to [ITextHost::TxActivate](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txactivate) is necessary to activate the control.

## See also

**Conceptual**

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

**Reference**

[TxActivate](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txactivate)

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)