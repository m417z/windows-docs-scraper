# IDirectManipulationPrimaryContent::SetSnapCoordinate

## Description

 Specifies the coordinate system for snap points or snap intervals.

## Parameters

### `motion` [in]

One of the values from [DIRECTMANIPULATION_MOTION_TYPES](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_motion_types).

### `coordinate` [in]

One of the values from [DIRECTMANIPULATION_SNAPPOINT_COORDINATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_snappoint_coordinate).

If *motion* is set to translation (**DIRECTMANIPULATION_MOTION_TRANSLATEX** or **DIRECTMANIPULATION_MOTION_TRANSLATEY**), all values of [DIRECTMANIPULATION_SNAPPOINT_COORDINATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_snappoint_coordinate) are valid.

If *motion* is set to **DIRECTMANIPULATION_MOTION_ZOOM**, only **DIRECTMANIPULATION_COORDINATE_ORIGIN** of [DIRECTMANIPULATION_SNAPPOINT_COORDINATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_snappoint_coordinate) is valid (*origin* must be set to 0.0f).

### `origin` [in]

The initial, or starting, snap point. All snap points are relative to this one. Only used when [DIRECTMANIPULATION_COORDINATE_ORIGIN](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_snappoint_coordinate) is set.

If *motion* is set to **DIRECTMANIPULATION_MOTION_ZOOM**, then *origin* must be set to 0.0f.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The origin is relative to the content boundaries. If no boundary has been set ([SetContentRect](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationcontent-setcontentrect) is never called) the default boundaries are (-[FLT_MAX](https://learn.microsoft.com/previous-versions/ms858507(v=msdn.10)), [FLT_MAX](https://learn.microsoft.com/previous-versions/ms858507(v=msdn.10))).

## See also

[IDirectManipulationPrimaryContent](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationprimarycontent)

[SetSnapInterval](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationprimarycontent-setsnapinterval)

[SetSnapPoints](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationprimarycontent-setsnappoints)