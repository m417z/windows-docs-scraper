# IOleControlSite::OnFocus

## Description

Indicates whether the control managed by this control site has gained or lost the focus.

## Parameters

### `fGotFocus` [in]

Indicates whether the control gained (TRUE) or lost the focus (FALSE).

## Return value

This method returns S_OK in all cases.

## Remarks

The container uses this information to update the state of **Default** and **Cancel** buttons according to how the control with the focus processes Return or Esc keys. A control's behavior regarding the Return and Esc keys is specified in the control's [CONTROLINFO](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-controlinfo) structure. See [IOleControl::GetControlInfo](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iolecontrol-getcontrolinfo) for more information.

## See also

[IOleControl::GetControlInfo](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iolecontrol-getcontrolinfo)

[IOleControlSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iolecontrolsite)