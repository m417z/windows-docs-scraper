# PATHDATA structure

## Description

The PATHDATA structure describes all or part of a subpath.

## Members

### `flags`

Flags describing the data returned are defined as follows:

| Value | Meaning |
| --- | --- |
| PD_ALL | This flag is the ORed combination of the other flags in this table. That is, PD_ALL == PD_BEGINSUBPATH \| PD_ENDSUBPATH \| PD_RESETSTYLE \| PD_CLOSEFIGURE \| PD_BEZIERS. |
| PD_BEGINSUBPATH | The first point begins a new subpath. It is not connected to the previous subpath. If this flag is not set, the starting point for the first curve to be drawn from this data is the last point returned in the previous call. |
| PD_BEZIERS | If set, each set of three control points returned for this call describes a Bezier curve. If clear, each control point describes a line segment. A starting point for either type is either explicit at the beginning of the subpath, or implicit as the endpoint of the previous curve. |
| PD_CLOSEFIGURE | This bit is only defined if the record ends a subpath. If set, there is an implicit line segment connecting the last point of the subpath with the first point. If such a closed subpath is being stroked, joins are used all around the path, and there are no end caps. If this flag is not set, the subpath is considered open, even if the first and last points happen to coincide. In that case, end caps should be drawn. This flag is not relevant to filling because all subpaths are assumed closed when a path is filled. |
| PD_ENDSUBPATH | The last point in the array ends the subpath. This subpath can be open or closed depending on the PD_CLOSEFIGURE flag. If there is more data to be returned in the path, the next record begins a new subpath. Note that a single record might begin and end a subpath. |
| PD_RESETSTYLE | This bit is defined only if this record begins a new subpath. If set, it indicates the style state should be reset to zero at the beginning of the subpath. If not set, the style state is defined by the LINEATTRS structure, or continues from the previous subpath. |

### `count`

Specifies the count of POINTFIX structures pointed to by **pptfx**.

### `pptfx`

Pointer to an array of POINTFIX structures that define the control points for the curves. These structures must not be modified. For a description of the POINTFIX structure, see [GDI Data Types](https://learn.microsoft.com/windows-hardware/drivers/display/gdi-data-types).

## Remarks

The PATHDATA structure describes all or part of a subpath. For example, a **MoveTo** call by an application within a path begins a new subpath.

## See also

[LINEATTRS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-lineattrs)

[PATHOBJ_bEnum](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_benum)