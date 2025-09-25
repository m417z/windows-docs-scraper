# IOleInPlaceSiteWindowless::InvalidateRgn

## Description

Enables an object to invalidate a specified region of its in-place image on the screen.

## Parameters

### `hRGN` [in]

The region to invalidate, in client coordinates of the containing window. If this parameter is **NULL**, the object's full extent is invalidated.

### `fErase` [in]

Specifies whether the background within the update region is to be erased when the region is updated. If this parameter is **TRUE**, the background is erased. If this parameter is **FALSE**, the background remains unchanged.

## Return value

This method returns S_OK on success.

## Remarks

An object is only allowed to invalidate pixels contained in its own site region. Any attempt to invalidate an area outside of that region should result in a no-op.

## See also

[IOleInPlaceSiteWindowless](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesitewindowless)