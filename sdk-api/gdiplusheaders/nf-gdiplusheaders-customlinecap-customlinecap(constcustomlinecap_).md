## Description

Copy constructor for **CustomLineCap**.

## Parameters

### `unnamedParam1`

The object to copy into this object.

## Remarks

The
*fillPath* and
*strokePath* parameters cannot be used at the same time. You should pass **NULL** to one of those two parameters. If you pass nonnull values to both parameters, then
*fillPath* is ignored.

The **CustomLineCap::CustomLineCap** class uses the winding fill mode regardless of the fill mode that is set for the
**GraphicsPath** object passed to the **CustomLineCap::CustomLineCap** constructor.