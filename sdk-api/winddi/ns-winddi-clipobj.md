# CLIPOBJ structure

## Description

The CLIPOBJ structure describes the clip region used when drawing.

## Members

### `iUniq`

Specifies a value that uniquely identifies the clip region. If **iUniq** is nonzero, the driver uses it as a cache identifier. This allows the driver to recognize a region after downloading and caching it. If the value is zero, the driver should not cache the region because the region will not be used again.

### `rclBounds`

Specifies a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that bounds the part of the region that intersects the drawing. If **iDComplexity** is DC_RECT, then this is the clipping rectangle to be considered.

### `iDComplexity`

Specifies the complexity of the part of the region that intersects with the drawing. This member must be one of the following values:

| Value | Meaning |
| --- | --- |
| DC_COMPLEX | The clip region must be enumerated. |
| DC_RECT | Clip to a single rectangle. |
| DC_TRIVIAL | Clipping need not be considered; draw the whole figure. |

### `iFComplexity`

Specifies the complexity of the whole region. This value is used by the driver in deciding whether to cache the region. [CLIPOBJ_cEnumStart](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-clipobj_cenumstart) can be called to determine the exact number of rectangles in the region. This member can be one of the following values:

| Value | Meaning |
| --- | --- |
| FC_COMPLEX | The region consists of more than four rectangles. |
| FC_RECT | The region is a single rectangle. |
| FC_RECT4 | The region consists of, at most, four rectangles. |

### `iMode`

Specifies how the region is stored by GDI. This can help the driver determine how to enumerate the region. This member can be one of the following values:

| Value | Meaning |
| --- | --- |
| TC_PATHOBJ | The region is stored as a path. |
| TC_RECTANGLES | The region is stored as rectangles. |

### `fjOptions`

Specifies clipping options. This member can be the following value:

| Value | Meaning |
| --- | --- |
| OC_BANK_CLIP | **Obsolete**. Indicates an engine callback for a banked device. |

## Remarks

The region, described by CLIPOBJ, can be enumerated as a series of rectangles.

## See also

[CLIPOBJ_bEnum](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-clipobj_benum)

[CLIPOBJ_cEnumStart](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-clipobj_cenumstart)

[RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl)