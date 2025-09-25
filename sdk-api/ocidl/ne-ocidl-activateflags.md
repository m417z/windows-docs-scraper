# ACTIVATEFLAGS enumeration

## Description

Indicates whether an object is activated as a windowless object. It is used in [IOleInPlaceSiteEx::OnInPlaceActivateEx](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesiteex).

## Constants

### `ACTIVATE_WINDOWLESS:1`

 Indicates that the object is activated in place as a windowless object. In the [IOleInPlaceSiteEx::OnInPlaceActivateEx](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesiteex) method, the container uses this value returned in the *dwFlags* parameter instead of calling the [IOleInPlaceObjectWindowless::GetWindow](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplaceobjectwindowless) method to determine if the object is windowless or not.

## See also

[IOleInPlaceSiteEx::OnInPlaceActivateEx](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesiteex)