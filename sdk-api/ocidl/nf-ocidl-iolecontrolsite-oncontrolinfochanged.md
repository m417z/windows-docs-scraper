# IOleControlSite::OnControlInfoChanged

## Description

Informs the container that the control's [CONTROLINFO](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-controlinfo) structure has changed and that the container should call the control's [IOleControl::GetControlInfo](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iolecontrol-getcontrolinfo) for an update.

## Return value

This method returns S_OK in all cases.

## See also

[IOleControl::GetControlInfo](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iolecontrol-getcontrolinfo)

[IOleControlSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iolecontrolsite)