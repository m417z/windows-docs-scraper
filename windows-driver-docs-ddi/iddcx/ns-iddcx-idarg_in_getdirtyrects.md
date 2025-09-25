# IDARG_IN_GETDIRTYRECTS structure

## Description

Gives information about the parts of the surface that have changed since the last present.

## Members

### `DirtyRectInCount`

 [in] Number of dirty rects in the **pDirtyRects** array

### `pDirtyRects`

 [out] Pointer to the buffer where the OS can copy the dirty rects that indicate which parts of the surface have been changed since the last present.