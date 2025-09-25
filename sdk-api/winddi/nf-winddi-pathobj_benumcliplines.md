# PATHOBJ_bEnumClipLines function

## Description

The **PATHOBJ_bEnumClipLines** function enumerates clipped line segments from a given path.

## Parameters

### `ppo`

Pointer to the [PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj) structure containing the clipped line segments that are to be enumerated.

### `cb`

Specifies the size of the output buffer, in bytes. GDI does not write beyond this point in the buffer. The value of this parameter must be large enough to hold a [CLIPLINE](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipline) structure with at least one [RUN](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-run) structure. The driver should allocate space for several RUN structures.

### `pcl`

Pointer to the buffer that receives a CLIPLINE structure. The structure contains the original unclipped control points for a line segment. (The correct pixels for the line cannot be computed without the original points.) RUN structures, which describe sets of pixels along the line that are not clipped away, are written to this buffer.

If a clip region is complex, a single line segment can be broken into many RUN structures. A segment is returned as many times as necessary to list all of its RUN structures.

The CLIPLINE structure contains the starting and ending points of the original unclipped line and the line segments, or RUN structures, of that line that are to appear on the display.

## Return value

The return value is **TRUE** if more line segments are to be enumerated, indicating that this service should be called again. Otherwise, it is **FALSE**, indicating that the returned segment is the last segment in the path.

## Remarks

The enumeration must be started with [PATHOBJ_vEnumStartClipLines](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_venumstartcliplines) before the driver makes this call.

## See also

[CLIPLINE](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipline)

[PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj)

[PATHOBJ_vEnumStartClipLines](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_venumstartcliplines)

[RUN](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-run)