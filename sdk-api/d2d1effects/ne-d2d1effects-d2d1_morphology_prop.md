# D2D1_MORPHOLOGY_PROP enumeration

## Description

Identifiers for properties of the [Morphology effect](https://learn.microsoft.com/windows/desktop/Direct2D/morphology).

## Constants

### `D2D1_MORPHOLOGY_PROP_MODE:0`

The morphology mode.

The type is D2D1_MORPHOLOGY_MODE.

The default value is D2D1_MORPHOLOGY_MODE_ERODE.

### `D2D1_MORPHOLOGY_PROP_WIDTH:1`

Size of the kernel in the X direction. The units are in DIPs. Values must be between 1 and 100 inclusive.

The type is UINT.

The default value is 1.

### `D2D1_MORPHOLOGY_PROP_HEIGHT:2`

Size of the kernel in the Y direction. The units are in DIPs. Values must be between 1 and 100 inclusive.

The type is UINT.

The default value is 1.

### `D2D1_MORPHOLOGY_PROP_FORCE_DWORD:0xffffffff`