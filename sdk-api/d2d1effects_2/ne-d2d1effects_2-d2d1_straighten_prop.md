# D2D1_STRAIGHTEN_PROP enumeration

## Description

Identifiers for properties of the [Straighten effect](https://learn.microsoft.com/windows/desktop/Direct2D/straighten-effect).

## Constants

### `D2D1_STRAIGHTEN_PROP_ANGLE:0`

The D2D1_STRAIGHTEN_PROP_ANGLE property is a float value that specifies how much the image should be rotated. The allowed range is -45.0 to 45.0. The default value is 0.0.

### `D2D1_STRAIGHTEN_PROP_MAINTAIN_SIZE:1`

The D2D1_STRAIGHTEN_PROP_MAINTAIN_SIZE property is a boolean value that specifies whether the image will be scaled such that the original size is maintained without any invalid regions.
The default value is True.

### `D2D1_STRAIGHTEN_PROP_SCALE_MODE:2`

The D2D1_STRAIGHTEN_PROP_SCALE_MODE property is a [D2D1_STRAIGHTEN_SCALE_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1effects_2/ne-d2d1effects_2-d2d1_straighten_scale_mode) enumeration value indicating the scaling mode that should be used.

### `D2D1_STRAIGHTEN_PROP_FORCE_DWORD:0xffffffff`