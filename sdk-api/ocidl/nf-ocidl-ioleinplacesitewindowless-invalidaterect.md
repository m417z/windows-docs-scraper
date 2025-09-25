# IOleInPlaceSiteWindowless::InvalidateRect

## Description

Enables an object to invalidate a specified rectangle of its in-place image on the screen.

## Parameters

### `pRect` [in]

The rectangle to be invalidated, in client coordinates of the containing window. If this parameter is **NULL**, the object's full extent is invalidated.

### `fErase` [in]

Specifies whether the background within the update region is to be erased when the region is updated. If this parameter is **TRUE**, the background is erased. If this parameter is **FALSE**, the background remains unchanged.

## Return value

This method returns S_OK on success.

## Remarks

An object is only allowed to invalidate pixels contained in its own site rectangle. Any attempt to invalidate an area outside of that rectangle should result in a no-op.

## See also

[IOleInPlaceSiteWindowless](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesitewindowless)