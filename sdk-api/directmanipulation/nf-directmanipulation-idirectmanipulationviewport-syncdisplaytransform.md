# IDirectManipulationViewport::SyncDisplayTransform

## Description

Specifies a display transform for the viewport, and synchronizes the output transform with the new value of the display transform.

## Parameters

### `matrix` [in]

The transform matrix, in row-wise order: _11, _12, _21, _22, _31, _32.

### `pointCount` [in]

The size of the transform matrix. This value is always 6, because a 3x2 matrix is used for all direct manipulation transforms.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the application performs special output processing of the content outside of the compositor (content not fully captured in the viewport transform), it should call this method to specify the display transform for the special processing.

The display transform affects how manipulation updates are applied to the output transform. For example, if the display transform is set to scale 3x, panning will move the content 3x the original distance.

When a display transform is changed using this method, the output transform will be synchronized to the new value of the display transform.

This method cannot be called if the viewport status is **DIRECTMANIPULATION_RUNNING** or **DIRECTMANIPULATION_INERTIA**.

## See also

[IDirectManipulationViewport](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport)