# DIRECTMANIPULATION_SNAPPOINT_TYPE enumeration

## Description

Modifies how the final inertia end position is calculated.

## Constants

### `DIRECTMANIPULATION_SNAPPOINT_MANDATORY:0`

Content always stops at the snap point closest to where inertia would naturally stop along the direction of inertia.

### `DIRECTMANIPULATION_SNAPPOINT_OPTIONAL:1`

Content stops at a snap point closest to where inertia would naturally stop along the direction of inertia, depending on how close the snap point is.

### `DIRECTMANIPULATION_SNAPPOINT_MANDATORY_SINGLE:2`

Content always stops at the snap point closest to the release point along the direction of inertia.

### `DIRECTMANIPULATION_SNAPPOINT_OPTIONAL_SINGLE:3`

Content stops at the next snap point, if the motion starts far from it.

## Remarks

For **DIRECTMANIPULATION_SNAPPOINT_MANDATORY** or **DIRECTMANIPULATION_SNAPPOINT_OPTIONAL** snap points, the snap points are chosen based on the natural ending position of inertia as calculated by the touch interaction engine. For **DIRECTMANIPULATION_SNAPPOINT_MANDATORY_SINGLE** or **DIRECTMANIPULATION_SNAPPOINT_OPTIONAL_SINGLE** snap points, the selected snap point depends on where inertia started.

## See also

[Direct Manipulation Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-enumerations)