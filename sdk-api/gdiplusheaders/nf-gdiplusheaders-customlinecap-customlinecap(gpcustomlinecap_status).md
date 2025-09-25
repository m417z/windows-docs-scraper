## Description

Creates a **CustomLineCap::CustomLineCap** object.

## Parameters

### `nativeCap`

Type: **[LineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-linecap)**

Optional. Element of the
[LineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-linecap) enumeration that specifies the line cap that will be used. The default value is LineCapFlat.

### `status`

TBD

## Remarks

The
*fillPath* and
*strokePath* parameters cannot be used at the same time. You should pass **NULL** to one of those two parameters. If you pass nonnull values to both parameters, then
*fillPath* is ignored.

The **CustomLineCap::CustomLineCap** class uses the winding fill mode regardless of the fill mode that is set for the
**GraphicsPath** object passed to the **CustomLineCap::CustomLineCap** constructor.