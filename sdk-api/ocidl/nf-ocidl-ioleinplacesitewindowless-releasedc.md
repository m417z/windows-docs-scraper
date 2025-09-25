# IOleInPlaceSiteWindowless::ReleaseDC

## Description

Releases the device context previously obtained by a call to [IOleInPlaceSiteWindowless::GetDC](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleinplacesitewindowless-getdc).

## Parameters

### `hDC` [in]

The device context to be released.

## Return value

This method returns S_OK on success.

## Remarks

An object calls this method to notify its container that the object is done with the device context. If the device context was used for drawing, the container should ensure that all overlapping objects are repainted correctly. If the device context was an offscreen device context, its content should also be copied to the screen in the rectangle originally passed to [IOleInPlaceSiteWindowless::GetDC](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleinplacesitewindowless-getdc). See **IOleInPlaceSiteWindowless::GetDC** for implementation notes relevant to **IOleInPlaceSiteWindowless::ReleaseDC**.

## See also

[IOleInPlaceSiteWindowless](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesitewindowless)

[IOleInPlaceSiteWindowless::GetDC](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleinplacesitewindowless-getdc)