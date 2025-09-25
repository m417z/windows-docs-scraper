## Description

Defines constants that specify attributes for a font axis. Values can be bitwise OR'd together.

## Constants

### `DWRITE_FONT_AXIS_ATTRIBUTES_NONE:0x0000`

Specifies no attributes.

### `DWRITE_FONT_AXIS_ATTRIBUTES_VARIABLE:0x0001`

Specifies that this axis is implemented as a variation axis in a variable font, with a continuous range of values, such as a range of weights from 100..900. Otherwise, it is either a static axis that holds a single point, or it has a range but doesn't vary, such as optical size in the Skia Heading font (which covers a range of points but doesn't interpolate any new glyph outlines).

### `DWRITE_FONT_AXIS_ATTRIBUTES_HIDDEN:0x0002`

Specifies that this axis is recommended to be remain hidden in user interfaces. The font developer may recommend this if an axis is intended to be accessed only programmatically, or is meant for font-internal or font-developer use only. The axis may be exposed in lower-level font inspection utilities, but should not be exposed in common nor even advanced-mode user interfaces in content-authoring apps.

## Remarks

## See also