# POINTF structure

## Description

Contains information that is used to convert between container units, expressed in floating point, and control units, expressed in **HIMETRIC**. The **POINTF** structure specifically holds the floating point container units. Controls do not attempt to interpret either value in the structure.

## Members

### `x`

The x coordinates of the point in units that the container finds convenient.

### `y`

The y coordinates of the point in units that the container finds convenient.

## See also

[IOleControlSite::TransformCoords](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iolecontrolsite-transformcoords)