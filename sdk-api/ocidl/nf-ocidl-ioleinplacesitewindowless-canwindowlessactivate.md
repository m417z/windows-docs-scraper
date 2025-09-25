# IOleInPlaceSiteWindowless::CanWindowlessActivate

## Description

Informs an object if its container can support it as a windowless object that can be in-place activated.

## Return value

This method returns S_OK if the object can activate in-place without a window.

## Remarks

If this method returns S_OK, the container can dispatch events to it using [IOleInPlaceObjectWindowless](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplaceobjectwindowless).

If this method returns S_FALSE, the object should create a window and behave as a normal compound document object.

## See also

[IOleInPlaceObjectWindowless](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplaceobjectwindowless)

[IOleInPlaceSiteWindowless](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesitewindowless)