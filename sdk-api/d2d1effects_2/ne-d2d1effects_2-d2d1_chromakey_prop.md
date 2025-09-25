# D2D1_CHROMAKEY_PROP enumeration

## Description

Identifiers for properties of the [Chroma-key effect](https://learn.microsoft.com/windows/desktop/Direct2D/chromakey-effect).

## Constants

### `D2D1_CHROMAKEY_PROP_COLOR:0`

The D2D1_CHROMAKEY_PROP_COLOR property is a vector4 value indicating the color that should be converted to alpha. The default color is black.

### `D2D1_CHROMAKEY_PROP_TOLERANCE:1`

The D2D1_CHROMAKEY_PROP_TOLERANCE property is a float value indicating the tolerance for matching the color specified in the D2D1_CHROMAKEY_PROP_COLOR property.
The allowed range is 0.0 to 1.0. The default value is 0.1.

### `D2D1_CHROMAKEY_PROP_INVERT_ALPHA:2`

The D2D1_CHROMAKEY_PROP_INVERT_ALPHA property is a boolean value indicating whether the alpha values should be inverted. The default value if False.

### `D2D1_CHROMAKEY_PROP_FEATHER:3`

The D2D1_CHROMAKEY_PROP_FEATHER property is a boolean value whether the edges of the output should be softened in the alpha channel.
When set to False, the alpha output by the effect is 1-bit: either fully opaque or fully transparent. Setting to True results in a softening of edges in the alpha channel of the Chroma Key output.
The default value is False.

### `D2D1_CHROMAKEY_PROP_FORCE_DWORD:0xffffffff`