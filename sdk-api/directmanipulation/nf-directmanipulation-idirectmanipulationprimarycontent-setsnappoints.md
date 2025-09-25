# IDirectManipulationPrimaryContent::SetSnapPoints

## Description

Specifies the snap points for the inertia rest position.

## Parameters

### `motion` [in]

One or more of the [DIRECTMANIPULATION_MOTION_TYPES](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_motion_types) enumeration values. Only **DIRECTMANIPULATION_MOTION_TRANSLATE_X**, **DIRECTMANIPULATION_MOTION_TRANSLATE_Y**, or **DIRECTMANIPULATION_MOTION_ZOOM** are allowed.

### `points` [in]

An array of snap points within the boundaries of the content to snap to. Should be specified in increasing order relative to the origin set in [SetSnapCoordinate](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationprimarycontent-setsnapcoordinate).

### `pointCount` [in]

 The size of the array of snap points. Should be greater than 0.

## Return value

If the method succeeds, it returns **S_OK**. If there is no change in the snap points, this method can return **S_FALSE**. Otherwise, it returns an **HRESULT** error code. If invalid snap points are specified, existing snap points might be affected.

## Remarks

If snap points are invalid (for example, outside of the content boundaries), they are ignored and the content is always within the content boundaries.

## See also

[IDirectManipulationPrimaryContent](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationprimarycontent)

[SetSnapCoordinate](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationprimarycontent-setsnapcoordinate)

[SetSnapInterval](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationprimarycontent-setsnapinterval)