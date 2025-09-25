# ITextHost::TxActivate

## Description

Notifies the text host that the control is active.

## Parameters

### `plOldState`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The previous activation state.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Return S_OK if the method succeeds.

Return the following COM error code if the method fails. For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_FAIL** | Activation is not possible at this time. |

## Remarks

It is legal for the host to refuse an activation request; for example, the control may be minimized and thus invisible.

The caller should be able to gracefully handle failure to activate.

No matter how many times this method is called, only one [ITextHost::TxDeactivate](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txdeactivate) call is necessary to deactivate the control.

This function returns an opaque handle in
*plOldState*. The caller (the text services object) should save this handle and use it in a subsequent call to [ITextHost::TxDeactivate](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txdeactivate).

## See also

**Conceptual**

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

**Reference**

[TxDeactivate](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txdeactivate)

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)