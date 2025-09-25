# IOleInPlaceSite::CanInPlaceActivate

## Description

Determines whether the container can activate the object in place.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The container does not allow in-place activation for this object. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

Only objects being displayed as DVASPECT_CONTENT can be activated in place.

### Notes to Callers

**CanInPlaceActivate** is called by the client site's immediate child object when this object must activate in place. This function allows the container application to accept or refuse the activation request.

## See also

[IOleInPlaceSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite)