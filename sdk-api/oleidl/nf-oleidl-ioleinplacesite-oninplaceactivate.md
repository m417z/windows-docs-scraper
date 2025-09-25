# IOleInPlaceSite::OnInPlaceActivate

## Description

Notifies the container that one of its objects is being activated in place.

## Return value

This method returns S_OK if the container allows the in-place activation.
Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

### Notes to Callers

**OnInPlaceActivate** is called by the active embedded object when it is activated in-place for the first time. The container should note that the object is becoming active.

### Notes to Implementers

A container that supports linking to embedded objects must properly manage the running of its in-place objects when they are UI-inactive and running in the hidden state. To reactivate the in-place object quickly, a container should not call [IOleObject::Close](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-close) until the container's [IOleInPlaceSite::DeactivateAndUndo](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-deactivateandundo) method is called. To help protect against the object being left in an unstable state if a linking client updates silently, the container should call [OleLockRunning](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olelockrunning) to lock the object in the running state. This prevents the hidden in-place object from shutting down before it can be saved in its container.

## See also

[IOleInPlaceSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite)