# LOGBRUSH structure

## Description

The **LOGBRUSH** structure defines the style, color, and pattern of a physical brush. It is used by the [CreateBrushIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createbrushindirect) and [ExtCreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extcreatepen) functions.

## Members

### `lbStyle`

The brush style. The **lbStyle** member must be one of the following styles.

| Value | Meaning |
| --- | --- |
| BS_DIBPATTERN | A pattern brush defined by a device-independent bitmap (DIB) specification. If **lbStyle** is BS_DIBPATTERN, the **lbHatch** member contains a handle to a packed DIB. For more information, see discussion in **lbHatch**. |
| BS_DIBPATTERN8X8 | See BS_DIBPATTERN. |
| BS_DIBPATTERNPT | A pattern brush defined by a device-independent bitmap (DIB) specification. If **lbStyle** is BS_DIBPATTERNPT, the **lbHatch** member contains a pointer to a packed DIB. For more information, see discussion in **lbHatch**. |
| BS_HATCHED | Hatched brush. |
| BS_HOLLOW | Hollow brush. |
| BS_NULL | Same as BS_HOLLOW. |
| BS_PATTERN | Pattern brush defined by a memory bitmap. |
| BS_PATTERN8X8 | See BS_PATTERN. |
| BS_SOLID | Solid brush. |

### `lbColor`

The color in which the brush is to be drawn. If **lbStyle** is the BS_HOLLOW or BS_PATTERN style, **lbColor** is ignored.

If **lbStyle** is BS_DIBPATTERN or BS_DIBPATTERNPT, the low-order word of **lbColor** specifies whether the **bmiColors** members of the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure contain explicit red, green, blue (RGB) values or indexes into the currently realized logical palette. The **lbColor** member must be one of the following values.

| Value | Meaning |
| --- | --- |
| DIB_PAL_COLORS | The color table consists of an array of 16-bit indexes into the currently realized logical palette. |
| DIB_RGB_COLORS | The color table contains literal RGB values. |

If **lbStyle** is BS_HATCHED or BS_SOLID, **lbColor** is a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) color value. To create a **COLORREF** color value, use the [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro.

### `lbHatch`

A hatch style. The meaning depends on the brush style defined by **lbStyle**.

If **lbStyle** is BS_DIBPATTERN, the **lbHatch** member contains a handle to a packed DIB. To obtain this handle, an application calls the [GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc) function with GMEM_MOVEABLE (or [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) with LMEM_MOVEABLE) to allocate a block of memory and then fills the memory with the packed DIB. A packed DIB consists of a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure immediately followed by the array of bytes that define the pixels of the bitmap.

If **lbStyle** is BS_DIBPATTERNPT, the **lbHatch** member contains a pointer to a packed DIB. The pointer derives from the memory block created by [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) with LMEM_FIXED set or by [GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc) with GMEM_FIXED set, or it is the pointer returned by a call like [LocalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-locallock) (handle_to_the_dib). A packed DIB consists of a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure immediately followed by the array of bytes that define the pixels of the bitmap.

If **lbStyle** is BS_HATCHED, the **lbHatch** member specifies the orientation of the lines used to create the hatch. It can be one of the following values.

| Value | Meaning |
| --- | --- |
| HS_BDIAGONAL | A 45-degree upward, left-to-right hatch |
| HS_CROSS | Horizontal and vertical cross-hatch |
| HS_DIAGCROSS | 45-degree crosshatch |
| HS_FDIAGONAL | A 45-degree downward, left-to-right hatch |
| HS_HORIZONTAL | Horizontal hatch |
| HS_VERTICAL | Vertical hatch |

If **lbStyle** is BS_PATTERN, **lbHatch** is a handle to the bitmap that defines the pattern. The bitmap cannot be a DIB section bitmap, which is created by the [CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection) function.

If **lbStyle** is BS_SOLID or BS_HOLLOW, **lbHatch** is ignored.

## Remarks

Although **lbColor** controls the foreground color of a hatch brush, the [SetBkMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbkmode) and [SetBkColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbkcolor) functions control the background color.

## See also

[BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo)

[Brush Structures](https://learn.microsoft.com/windows/desktop/gdi/brush-structures)

[Brushes Overview](https://learn.microsoft.com/windows/desktop/gdi/brushes)

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[CreateBrushIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createbrushindirect)

[CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection)

[ExtCreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extcreatepen)

[LOGBRUSH32](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logbrush32)

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)

[SetBkColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbkcolor)

[SetBkMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbkmode)