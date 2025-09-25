# D2D1_ARITHMETICCOMPOSITE_PROP enumeration

## Description

Identifiers for the properties of the [Arithmetic composite effect](https://learn.microsoft.com/windows/desktop/Direct2D/arithmetic-composite).

## Constants

### `D2D1_ARITHMETICCOMPOSITE_PROP_COEFFICIENTS:0`

The coefficients for the equation used to composite the two input images. The coefficients are unitless and unbounded.

Type is D2D1_VECTOR_4F.

Default value is {1.0f, 0.0f, 0.0f, 0.0f}.

### `D2D1_ARITHMETICCOMPOSITE_PROP_CLAMP_OUTPUT:1`

The effect clamps color values to between 0 and 1 before the effect passes the values to the next effect in the graph.
If you set this to TRUE the effect will clamp the values. If you set this to FALSE, the effect will not clamp the color values,
but other effects and the output surface may clamp the values if they are not of high enough precision.

Type is BOOL.

Default value is FALSE.

### `D2D1_ARITHMETICCOMPOSITE_PROP_FORCE_DWORD:0xffffffff`