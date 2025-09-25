# D2D1_FLOOD_PROP enumeration

## Description

Identifiers for properties of the [Flood effect](https://learn.microsoft.com/windows/desktop/Direct2D/flood).

## Constants

### `D2D1_FLOOD_PROP_COLOR:0`

The color and opacity of the bitmap. This property is a D2D1_VECTOR_4F. The individual values for each channel are of type FLOAT, unbounded and unitless.
The effect doesn't modify the values for the channels.

The RGBA values for each channel range from 0 to 1.

The type is [D2D1_VECTOR_4F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_vector_4f).

The default value is {0.0f, 0.0f, 0.0f, 1.0f}.

### `D2D1_FLOOD_PROP_FORCE_DWORD:0xffffffff`