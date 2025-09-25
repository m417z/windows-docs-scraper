# IOleControl::FreezeEvents

## Description

Indicates whether the container is ignoring or accepting events from the control.

## Parameters

### `bFreeze` [in]

Indicates whether the container will ignore (**TRUE**) or now process (**FALSE**) events from the control.

## Return value

This method returns S_OK in all cases.

## Remarks

The control is not required to stop sending events when *bFreeze* is **TRUE**. However, the container is not going to process them in this case. If a control depends on the container's processing -- as with request events that return information from the container -- the control must either discard the event or queue the event to send later when *bFreeze* is **FALSE**.

### Notes to Implementers

As with [IOleControl::OnAmbientPropertyChange](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iolecontrol-onambientpropertychange), S_OK is returned in all cases in order to prevent a container from making assumptions about a control's behavior based on return values.

## See also

[IOleControl](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iolecontrol)