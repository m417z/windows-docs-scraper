# D2D1_GAMMATRANSFER_PROP enumeration

## Description

Identifiers for properties of the [Gamma transfer effect](https://learn.microsoft.com/windows/desktop/Direct2D/gamma-transfer).

## Constants

### `D2D1_GAMMATRANSFER_PROP_RED_AMPLITUDE:0`

The amplitude of the gamma transfer function for the Red channel.

The type is FLOAT.

The default value is 1.0f.

### `D2D1_GAMMATRANSFER_PROP_RED_EXPONENT:1`

The exponent of the gamma transfer function for the Red channel.

The type is FLOAT.

The default value is 1.0f.

### `D2D1_GAMMATRANSFER_PROP_RED_OFFSET:2`

The offset of the gamma transfer function for the Red channel.

The type is FLOAT.

The default value is 0.0f.

### `D2D1_GAMMATRANSFER_PROP_RED_DISABLE:3`

If you set this to TRUE it does not apply the transfer function to the Red channel. An identity transfer function is used.
If you set this to FALSE it applies the gamma transfer function to the Red channel.

The type is BOOL.

The default value is FALSE.

### `D2D1_GAMMATRANSFER_PROP_GREEN_AMPLITUDE:4`

The amplitude of the gamma transfer function for the Green channel.

The type is FLOAT.

The default value is 1.0f.

### `D2D1_GAMMATRANSFER_PROP_GREEN_EXPONENT:5`

The exponent of the gamma transfer function for the Green channel.

The type is FLOAT.

The default value is 1.0f.

### `D2D1_GAMMATRANSFER_PROP_GREEN_OFFSET:6`

The offset of the gamma transfer function for the Green channel.

The type is FLOAT.

The default value is 0.0f.

### `D2D1_GAMMATRANSFER_PROP_GREEN_DISABLE:7`

If you set this to TRUE it does not apply the transfer function to the Green channel. An identity transfer function is used.
If you set this to FALSE it applies the gamma transfer function to the Green channel.

The type is BOOL.

The default value is FALSE.

### `D2D1_GAMMATRANSFER_PROP_BLUE_AMPLITUDE:8`

The amplitude of the gamma transfer function for the Blue channel.

The type is FLOAT.

The default value is 1.0f.

### `D2D1_GAMMATRANSFER_PROP_BLUE_EXPONENT:9`

The exponent of the gamma transfer function for the Blue channel.

The type is FLOAT.

The default value is 1.0f.

### `D2D1_GAMMATRANSFER_PROP_BLUE_OFFSET:10`

The offset of the gamma transfer function for the Blue channel.

The type is FLOAT.

The default value is 0.0f.

### `D2D1_GAMMATRANSFER_PROP_BLUE_DISABLE:11`

If you set this to TRUE it does not apply the transfer function to the Blue channel. An identity transfer function is used.
If you set this to FALSE it applies the gamma transfer function to the Blue channel.

The type is BOOL.

The default value is FALSE.

### `D2D1_GAMMATRANSFER_PROP_ALPHA_AMPLITUDE:12`

The amplitude of the gamma transfer function for the Alpha channel.

The type is FLOAT.

The default value is 1.0f.

### `D2D1_GAMMATRANSFER_PROP_ALPHA_EXPONENT:13`

The exponent of the gamma transfer function for the Alpha channel.

The type is FLOAT.

The default value is 1.0f.

### `D2D1_GAMMATRANSFER_PROP_ALPHA_OFFSET:14`

The offset of the gamma transfer function for the Alpha channel.

The type is FLOAT.

The default value is 0.0f.

### `D2D1_GAMMATRANSFER_PROP_ALPHA_DISABLE:15`

If you set this to TRUE it does not apply the transfer function to the Alpha channel. An identity transfer function is used.
If you set this to FALSE it applies the gamma transfer function to the Alpha channel.

The type is BOOL.

The default value is FALSE.

### `D2D1_GAMMATRANSFER_PROP_CLAMP_OUTPUT:16`

Whether the effect clamps color values to between 0 and 1 before the effect passes the values to the next effect in the graph.
The effect clamps the values before it premultiplies the alpha.

If you set this to TRUE the effect will clamp the values. If you set this to FALSE, the effect will not clamp the color values,
but other effects and the output surface may clamp the values if they are not of high enough precision.

The type is BOOL.

The default value is FALSE.

### `D2D1_GAMMATRANSFER_PROP_FORCE_DWORD:0xffffffff`