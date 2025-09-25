# DIRECTMANIPULATION_SNAPPOINT_COORDINATE enumeration

## Description

Defines the coordinate system for a collection of snap points.

## Constants

### `DIRECTMANIPULATION_COORDINATE_BOUNDARY:0`

Default.

Snap points are specified relative to the top and left boundaries of the content unless **DIRECTMANIPULATION_COORDINATE_MIRRORED** is also specified, in which case they are relative to the bottom and right boundaries of the content. For zoom, the boundary is 1.0f.

### `DIRECTMANIPULATION_COORDINATE_ORIGIN:0x1`

Snap points are specified relative to the origin of the viewport.

### `DIRECTMANIPULATION_COORDINATE_MIRRORED:0x10`

Snap points are interpreted as specified in the negative direction of the origin. The origin is shifted to the bottom and right of the viewport or content. Cannot be set for zoom.

## Remarks

If **DIRECTMANIPULATION_COORDINATE_ORIGIN** and **DIRECTMANIPULATION_COORDINATE_MIRRORED** are both specified, the snap points are interpreted as specified from the bottom and right boundaries of the content (the size of the content - the size of the viewport). This is intended for RTL reading scenarios where content is normally specified and rendered from right-to-left or bottom-to-top.

## See also

[Direct Manipulation Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-enumerations)

[SetSnapCoordinate](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationprimarycontent-setsnapcoordinate)