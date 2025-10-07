# Pen::Pen(IN const Brush,IN REAL)

## Description

Creates a [Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object that uses the attributes of a brush and a real number to set the width of this **Pen** object.

## Parameters

### `brush` [in]

Type: **const [Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush)***

Pointer to a brush to base this pen on.

### `width` [in]

Type: **REAL**

Optional. Real number that specifies the width of this pen's stroke. The default value is 1.0. If this value is 0, the width in device units is always 1 pixel, except that the `width` will not be affected by scale-transform operations that are in effect for the Graphics object that the \<xref:System.Drawing.Pen> is used for; the width will always be 1 pixel.

## Remarks

If you pass the address of a pen to one of the draw methods of a
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object, the width of the pen's stroke is dependent on the unit of measure specified in the
**Graphics** object. The default unit of measure is **UnitPixel**, which is an element of the
[Unit](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-unit) enumeration.

#### Examples

The following example creates a [Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush) object and then creates a [Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object based on the **Brush** object.

```cpp
SolidBrush sBrush(Color(255,255,0,0));
Pen pen(&sBrush, 4.0f);
```

## See also

[Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-pen(constpen_))

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)

[Setting Pen Width and Alignment](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-setting-pen-width-and-alignment-use)