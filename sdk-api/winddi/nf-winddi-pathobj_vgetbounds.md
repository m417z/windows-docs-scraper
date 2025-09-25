# PATHOBJ_vGetBounds function

## Description

The **PATHOBJ_vGetBounds** function retrieves the bounding rectangle for the specified path.

## Parameters

### `ppo`

Pointer to a [PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj) structure that describes the path for which a bounding rectangle is to be calculated.

### `prectfx`

Pointer to the address where the RECTFX structure is to be written. The returned rectangle is exclusive of the bottom and right edges. An empty rectangle is specified by setting all four RECTFX members to zero. For a description of this data type, see [GDI Data Types](https://learn.microsoft.com/windows-hardware/drivers/display/gdi-data-types).

## Return value

None

## See also

[PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj)