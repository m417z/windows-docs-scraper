# IOleControlSite::LockInPlaceActive

## Description

Indicates whether a control should remain in-place active. Calls to this method typically nest an event to ensure that the object's activation state remains stable throughout the processing of the event.

## Parameters

### `fLock` [in]

Indicates whether to ensure the in-place active state (**TRUE**) or to allow activation to change (**FALSE**). When **TRUE**, a supporting container must not deactivate the in-place object until this method is called again with **FALSE**.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The lock or unlock was made successfully. |
| **E_NOTIMPL** | The container does not support in-place locking. |

## Remarks

This method affects the control's in-place active state but not its UI-active state.

## See also

[IOleControlSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iolecontrolsite)