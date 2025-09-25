# XPS_DASH structure

## Description

This structure describes a dash element of a path.

## Members

### `length`

Length of the visible segment of the dash element.

### `gap`

Length of the space between the visible segments of the dash sequence.

## Remarks

The length must be non-negative and is measured in multiples of the path's stroke thickness.

 Values of **length** do not include the end caps of the visible segments.

The shape of the end caps of the visible segments is determined by the [XPS_DASH_CAP](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_dash_cap) value.

## See also

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS_DASH_CAP](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_dash_cap)