# XMFLOAT3SE::XMFLOAT3SE(float,float,float)

## Description

Initializes a new instance of `XMFLOAT3SE` from three `float` arguments.

This constructor initializes a new instance of [XMFLOAT3SE](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmfloat3se) from three
`float` arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_x`

Value to be stored in the x-component of the new instance of `XMFLOAT3SE`.

The value stored is transformed from the standard 32 floating point format (sign bit,
8 bit exponent, 23 bit mantissa), to a 14 bit floating point format (9 bit mantissa,
and 5 bit exponent).

### `_y`

Value to be stored in the y-component of the new instance of `XMFLOAT3SE`.

The value stored is transformed from the standard 32 floating point format (sign bit,
8 bit exponent, 23 bit mantissa), to a 14 bit floating point format (9 bit mantissa,
and 5 bit exponent).

### `_z`

Value to be stored in the z-component of the new instance of `XMFLOAT3SE`.

The value stored is transformed from the standard 32 floating point format (sign bit,
8 bit exponent, 23 bit mantissa), to a 14 bit floating point format (9 bit mantissa,
and 5 bit exponent).

## Remarks

As the floating point storage formats used by `XMFLOAT3SE` do not support a sign
bit, all arguments to this constructor must be greater than or equal to zero.

The floating point values of all components are all expressed using the same exponent,
which is stored in the **e** member of the new instance of `XMFLOAT3SE` instantiated by this constructor.

Because of the change in floating point format during the instantiation of an instance of
`XMFLOAT3SE`, some loss of precision can be expected.

## See also

**Reference**

[XMFLOAT3SE](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmfloat3se)

[XMFLOAT3SE Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmfloat3se-ctor)