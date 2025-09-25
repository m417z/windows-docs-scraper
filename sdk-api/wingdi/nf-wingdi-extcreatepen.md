# ExtCreatePen function

## Description

The **ExtCreatePen** function creates a logical cosmetic or geometric pen that has the specified style, width, and brush attributes.

## Parameters

### `iPenStyle` [in]

A combination of type, style, end cap, and join attributes. The values from each category are combined by using the bitwise OR operator ( | ).

The pen type can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PS_GEOMETRIC** | The pen is geometric. |
| **PS_COSMETIC** | The pen is cosmetic. |

The pen style can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PS_ALTERNATE** | The pen sets every other pixel. (This style is applicable only for cosmetic pens.) |
| **PS_SOLID** | The pen is solid. |
| **PS_DASH** | The pen is dashed. |
| **PS_DOT** | The pen is dotted. |
| **PS_DASHDOT** | The pen has alternating dashes and dots. |
| **PS_DASHDOTDOT** | The pen has alternating dashes and double dots. |
| **PS_NULL** | The pen is invisible. |
| **PS_USERSTYLE** | The pen uses a styling array supplied by the user. |
| **PS_INSIDEFRAME** | The pen is solid. When this pen is used in any GDI drawing function that takes a bounding rectangle, the dimensions of the figure are shrunk so that it fits entirely in the bounding rectangle, taking into account the width of the pen. This applies only to geometric pens. |

The end cap is only specified for geometric pens. The end cap can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PS_ENDCAP_ROUND** | End caps are round. |
| **PS_ENDCAP_SQUARE** | End caps are square. |
| **PS_ENDCAP_FLAT** | End caps are flat. |

The join is only specified for geometric pens. The join can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PS_JOIN_BEVEL** | Joins are beveled. |
| **PS_JOIN_MITER** | Joins are mitered when they are within the current limit set by the [SetMiterLimit](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setmiterlimit) function. If it exceeds this limit, the join is beveled. |
| **PS_JOIN_ROUND** | Joins are round. |

### `cWidth` [in]

The width of the pen. If the *dwPenStyle* parameter is PS_GEOMETRIC, the width is given in logical units. If *dwPenStyle* is PS_COSMETIC, the width must be set to 1.

### `plbrush` [in]

A pointer to a [LOGBRUSH](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logbrush) structure. If *dwPenStyle* is PS_COSMETIC, the **lbColor** member specifies the color of the pen and the **lpStyle** member must be set to BS_SOLID. If *dwPenStyle* is PS_GEOMETRIC, all members must be used to specify the brush attributes of the pen.

### `cStyle` [in]

The length, in **DWORD** units, of the *lpStyle* array. This value must be zero if *dwPenStyle* is not PS_USERSTYLE.

The style count is limited to 16.

### `pstyle` [in]

A pointer to an array. The first value specifies the length of the first dash in a user-defined style, the second value specifies the length of the first space, and so on. This pointer must be **NULL** if *dwPenStyle* is not PS_USERSTYLE.

If the *lpStyle* array is exceeded during line drawing, the pointer is reset to the beginning of the array. When this happens and *dwStyleCount* is an even number, the pattern of dashes and spaces repeats. However, if *dwStyleCount* is odd, the pattern reverses when the pointer is reset -- the first element of *lpStyle* now refers to spaces, the second refers to dashes, and so forth.

## Return value

If the function succeeds, the return value is a handle that identifies a logical pen.

If the function fails, the return value is zero.

## Remarks

A geometric pen can have any width and can have any of the attributes of a brush, such as dithers and patterns. A cosmetic pen can only be a single pixel wide and must be a solid color, but cosmetic pens are generally faster than geometric pens.

The width of a geometric pen is always specified in world units. The width of a cosmetic pen is always 1.

End caps and joins are only specified for geometric pens.

After an application creates a logical pen, it can select that pen into a device context by calling the [SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject) function. After a pen is selected into a device context, it can be used to draw lines and curves.

If *dwPenStyle* is PS_COSMETIC and PS_USERSTYLE, the entries in the *lpStyle* array specify lengths of dashes and spaces in style units. A style unit is defined by the device where the pen is used to draw a line.

If *dwPenStyle* is PS_GEOMETRIC and PS_USERSTYLE, the entries in the *lpStyle* array specify lengths of dashes and spaces in logical units.

If *dwPenStyle* is PS_ALTERNATE, the style unit is ignored and every other pixel is set.

If the **lbStyle** member of the [LOGBRUSH](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logbrush) structure pointed to by *lplb* is BS_PATTERN, the bitmap pointed to by the **lbHatch** member of that structure cannot be a DIB section. A DIB section is a bitmap created by [CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection). If that bitmap is a DIB section, the **ExtCreatePen** function fails.

When an application no longer requires a specified pen, it should call the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete the pen.

**ICM:** No color management is done at pen creation. However, color management is performed when the pen is selected into an ICM-enabled device context.

#### Examples

For an example, see [Using Pens](https://learn.microsoft.com/windows/desktop/gdi/using-pens).

## See also

[CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection)

[CreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpen)

[CreatePenIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpenindirect)

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

[GetObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getobject)

[LOGBRUSH](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logbrush)

[Pen Functions](https://learn.microsoft.com/windows/desktop/gdi/pen-functions)

[Pens Overview](https://learn.microsoft.com/windows/desktop/gdi/pens)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)

[SetMiterLimit](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setmiterlimit)