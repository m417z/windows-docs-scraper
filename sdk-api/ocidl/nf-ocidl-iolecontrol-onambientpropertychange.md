# IOleControl::OnAmbientPropertyChange

## Description

Informs a control that one or more of the container's ambient properties has changed.

## Parameters

### `dispID` [in]

The dispatch identifier of the ambient property that changed. If this parameter is DISPID_UNKNOWN, it indicates that multiple properties changed. In this case, the control should check all the ambient properties of interest to obtain their current values.

## Return value

This method returns S_OK in all cases.

## Remarks

### Notes to Implementers

S_OK is returned in all cases even when the control does not support ambient properties or some other failure has occurred. The caller sending the notification cannot attempt to use an error code (such as E_NOTIMPL) to determine whether to send the notification in the future. Such semantics are not part of this interface.

## See also

[IOleControl](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iolecontrol)