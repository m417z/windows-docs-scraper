# D2D1_BRIGHTNESS_PROP enumeration

## Description

Identifiers for the properties of the [Brightness effect](https://learn.microsoft.com/windows/desktop/Direct2D/brightness).

## Constants

### `D2D1_BRIGHTNESS_PROP_WHITE_POINT:0`

The upper portion of the brightness transfer curve. The white point adjusts the appearance of the brighter portions of the image.
This property is for both the x value and the y value, in that order. Each of the values of this property are between 0 and 1, inclusive.

The type is [D2D1_VECTOR_2F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_vector_2f).

The default value is (1.0f, 1.0f).

### `D2D1_BRIGHTNESS_PROP_BLACK_POINT:1`

The lower portion of the brightness transfer curve. The black point adjusts the appearance of the darker portions of the image.
This property is for both the x value and the y value, in that order. Each of the values of this property are between 0 and 1, inclusive.

The type is [D2D1_VECTOR_2F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_vector_2f).

The default value is (0.0f, 0.0f).

### `D2D1_BRIGHTNESS_PROP_FORCE_DWORD:0xffffffff`