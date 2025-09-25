# EXTLOGPEN structure

## Description

The **EXTLOGPEN** structure defines the pen style, width, and brush attributes for an extended pen. This structure is used by the [GetObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getobject) function when it retrieves a description of a pen that was created when an application called the [ExtCreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extcreatepen) function.

## Members

### `elpPenStyle`

A combination of pen type, style, end cap style, and join style. The values from each category can be retrieved by using a bitwise AND operator with the appropriate mask.

The **elpPenStyle** member masked with PS_TYPE_MASK has one of the following pen type values.

| Value | Meaning |
| --- | --- |
| PS_GEOMETRIC | The pen is geometric. |
| PS_COSMETIC | The pen is cosmetic. |

The **elpPenStyle** member masked with PS_STYLE_MASK has one of the following pen styles values:

| Value | Meaning |
| --- | --- |
| PS_DASH | The pen is dashed. |
| PS_DASHDOT | The pen has alternating dashes and dots. |
| PS_DASHDOTDOT | The pen has alternating dashes and double dots. |
| PS_DOT | The pen is dotted. |
| PS_INSIDEFRAME | The pen is solid. When this pen is used in any GDI drawing function that takes a bounding rectangle, the dimensions of the figure are shrunk so that it fits entirely in the bounding rectangle, taking into account the width of the pen. This applies only to PS_GEOMETRIC pens. |
| PS_NULL | The pen is invisible. |
| PS_SOLID | The pen is solid. |
| PS_USERSTYLE | The pen uses a styling array supplied by the user. |

The following category applies only to PS_GEOMETRIC pens. The **elpPenStyle** member masked with PS_ENDCAP_MASK has one of the following end cap values.

| Value | Meaning |
| --- | --- |
| PS_ENDCAP_FLAT | Line end caps are flat. |
| PS_ENDCAP_ROUND | Line end caps are round. |
| PS_ENDCAP_SQUARE | Line end caps are square. |

The following category applies only to PS_GEOMETRIC pens. The **elpPenStyle** member masked with PS_JOIN_MASK has one of the following join values.

| Value | Meaning |
| --- | --- |
| PS_JOIN_BEVEL | Line joins are beveled. |
| PS_JOIN_MITER | Line joins are mitered when they are within the current limit set by the [SetMiterLimit](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setmiterlimit) function. A join is beveled when it would exceed the limit. |
| PS_JOIN_ROUND | Line joins are round. |

### `elpWidth`

The width of the pen. If the **elpPenStyle** member is PS_GEOMETRIC, this value is the width of the line in logical units. Otherwise, the lines are cosmetic and this value is 1, which indicates a line with a width of one pixel.

### `elpBrushStyle`

The brush style of the pen. The **elpBrushStyle** member value can be one of the following.

| Value | Meaning |
| --- | --- |
| BS_DIBPATTERN | Specifies a pattern brush defined by a DIB specification. If **elpBrushStyle** is BS_DIBPATTERN, the **elpHatch** member contains a handle to a packed DIB. For more information, see discussion in **elpHatch** |
| BS_DIBPATTERNPT | Specifies a pattern brush defined by a DIB specification. If **elpBrushStyle** is BS_DIBPATTERNPT, the **elpHatch** member contains a pointer to a packed DIB. For more information, see discussion in **elpHatch**. |
| BS_HATCHED | Specifies a hatched brush. |
| BS_HOLLOW | Specifies a hollow or **NULL** brush. |
| BS_PATTERN | Specifies a pattern brush defined by a memory bitmap. |
| BS_SOLID | Specifies a solid brush. |

### `elpColor`

If **elpBrushStyle** is BS_SOLID or BS_HATCHED, **elpColor** specifies the color in which the pen is to be drawn. For BS_HATCHED, the [SetBkMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbkmode) and [SetBkColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbkcolor) functions determine the background color.

If **elpBrushStyle** is BS_HOLLOW or BS_PATTERN, **elpColor** is ignored.

If **elpBrushStyle** is BS_DIBPATTERN or BS_DIBPATTERNPT, the low-order word of **elpColor** specifies whether the **bmiColors** member of the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure contain explicit RGB values or indices into the currently realized logical palette. The **elpColor** value must be one of the following.

| Value | Meaning |
| --- | --- |
| DIB_PAL_COLORS | The color table consists of an array of 16-bit indices into the currently realized logical palette. |
| DIB_RGB_COLORS | The color table contains literal RGB values. |

The [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro is used to generate a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) structure.

### `elpHatch`

If **elpBrushStyle** is BS_PATTERN, **elpHatch** is a handle to the bitmap that defines the pattern.

If **elpBrushStyle** is BS_SOLID or BS_HOLLOW, **elpHatch** is ignored.

If **elpBrushStyle** is BS_DIBPATTERN, the **elpHatch** member is a handle to a packed DIB. To obtain this handle, an application calls the [GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc) function with GMEM_MOVEABLE (or [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) with LMEM_MOVEABLE) to allocate a block of memory and then fills the memory with the packed DIB. A packed DIB consists of a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure immediately followed by the array of bytes that define the pixels of the bitmap.

If **elpBrushStyle** is BS_DIBPATTERNPT, the **elpHatch** member is a pointer to a packed DIB. The pointer derives from the memory block created by [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) with LMEM_FIXED set or by [GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc) with GMEM_FIXED set, or it is the pointer returned by a call like [LocalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-locallock) (handle_to_the_dib). A packed DIB consists of a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure immediately followed by the array of bytes that define the pixels of the bitmap.

If **elpBrushStyle** is BS_HATCHED, the **elpHatch** member specifies the orientation of the lines used to create the hatch. It can be one of the following values.

| Value | Meaning |
| --- | --- |
| HS_BDIAGONAL | 45-degree upward hatch (left to right) |
| HS_CROSS | Horizontal and vertical crosshatch |
| HS_DIAGCROSS | 45-degree crosshatch |
| HS_FDIAGONAL | 45-degree downward hatch (left to right) |
| HS_HORIZONTAL | Horizontal hatch |
| HS_VERTICAL | Vertical hatch |

### `elpNumEntries`

The number of entries in the style array in the **elpStyleEntry** member. This value is zero if **elpPenStyle** does not specify PS_USERSTYLE.

### `elpStyleEntry`

A user-supplied style array. The array is specified with a finite length, but it is used as if it repeated indefinitely. The first entry in the array specifies the length of the first dash. The second entry specifies the length of the first gap. Thereafter, lengths of dashes and gaps alternate.

If **elpWidth** specifies geometric lines, the lengths are in logical units. Otherwise, the lines are cosmetic and lengths are in device units.

## See also

[BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo)

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[ExtCreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extcreatepen)

[GetObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getobject)

[Pen Structures](https://learn.microsoft.com/windows/desktop/gdi/pen-structures)

[Pens Overview](https://learn.microsoft.com/windows/desktop/gdi/pens)

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)

[SetBkColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbkcolor)

[SetBkMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbkmode)