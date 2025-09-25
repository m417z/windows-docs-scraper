# IOleControl::OnMnemonic

## Description

Informs a control that the user has pressed a keystroke that represents a keyboard mnemonic.

## Parameters

### `pMsg` [in]

A pointer to the [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure describing the keystroke to be processed.

## Return value

This method can return the standard return values E_INVALIDARG and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_NOTIMPL** | The control does not handle mnemonics. This indicates an unexpected condition and a caller error. For example, the caller has mismatched which control has which mnemonic. |

## Remarks

The keystroke must match one of the **ACCEL** entries in the mnemonic table returned through [IOleControl::GetControlInfo](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iolecontrol-getcontrolinfo). The control takes whatever action is appropriate for the keystroke.

### Notes to Callers

A container of a control is allowed to cache the control's [CONTROLINFO](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-controlinfo) structure, provided that the container implements [IOleControlSite::OnControlInfoChanged](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iolecontrolsite-oncontrolinfochanged) to know when it must update its cached information.

### Notes to Implementers

If a control changes the contents of its [CONTROLINFO](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-controlinfo) structure, it must notify its container by calling [IOleControlSite::OnControlInfoChanged](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iolecontrolsite-oncontrolinfochanged).

## See also

[IOleControl](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iolecontrol)

[IOleControlSite::OnControlInfoChanged](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iolecontrolsite-oncontrolinfochanged)