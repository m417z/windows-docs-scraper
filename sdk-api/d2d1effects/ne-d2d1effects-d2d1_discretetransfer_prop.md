# D2D1_DISCRETETRANSFER_PROP enumeration

## Description

Identifiers for properties of the [Discrete transfer effect](https://learn.microsoft.com/windows/desktop/Direct2D/discrete-transfer).

## Constants

### `D2D1_DISCRETETRANSFER_PROP_RED_TABLE:0`

The list of values used to define the transfer function for the Red channel.

The type is FLOAT[].

The default value is {0.0f, 1.0f}.

### `D2D1_DISCRETETRANSFER_PROP_RED_DISABLE:1`

If you set this to TRUE the effect does not apply the transfer function to the Red channel.
If you set this to FALSE the effect applies the RedDiscreteTransfer function to the Red channel.

The type is BOOL.

The default value if FALSE.

### `D2D1_DISCRETETRANSFER_PROP_GREEN_TABLE:2`

The list of values used to define the transfer function for the Green channel.

The type is FLOAT[].

The default value is {0.0f, 1.0f}.

### `D2D1_DISCRETETRANSFER_PROP_GREEN_DISABLE:3`

If you set this to TRUE the effect does not apply the transfer function to the Green channel.
If you set this to FALSE the effect applies the GreenDiscreteTransfer function to the Green channel.

The type is BOOL.

The default value if FALSE.

### `D2D1_DISCRETETRANSFER_PROP_BLUE_TABLE:4`

The list of values used to define the transfer function for the Blue channel.

The type is FLOAT[].

The default value is {0.0f, 1.0f}.

### `D2D1_DISCRETETRANSFER_PROP_BLUE_DISABLE:5`

If you set this to TRUE the effect does not apply the transfer function to the Blue channel.
If you set this to FALSE the effect applies the BlueDiscreteTransfer function to the Blue channel.

The type is BOOL.

The default value if FALSE.

### `D2D1_DISCRETETRANSFER_PROP_ALPHA_TABLE:6`

The list of values used to define the transfer function for the Alpha channel.

The type is FLOAT[].

The default value is {0.0f, 1.0f}.

### `D2D1_DISCRETETRANSFER_PROP_ALPHA_DISABLE:7`

If you set this to TRUE the effect does not apply the transfer function to the Alpha channel.
If you set this to FALSE the effect applies the AlphaDiscreteTransfer function to the Alpha channel.

The type is BOOL.

The default value if FALSE.

### `D2D1_DISCRETETRANSFER_PROP_CLAMP_OUTPUT:8`

Whether the effect clamps color values to between 0 and 1 before the effect passes the values to the next effect in the graph.
The effect clamps the values before it premultiplies the alpha.

If you set this to TRUE the effect will clamp the values. If you set this to FALSE, the effect will not clamp the color values,
but other effects and the output surface may clamp the values if they are not of high enough precision.

The type is BOOL.

The default value if FALSE.

### `D2D1_DISCRETETRANSFER_PROP_FORCE_DWORD:0xffffffff`