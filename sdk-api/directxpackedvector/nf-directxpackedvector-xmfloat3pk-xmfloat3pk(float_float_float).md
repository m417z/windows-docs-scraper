# XMFLOAT3PK::XMFLOAT3PK(float,float,float)

## Description

Initializes a new instance of `XMFLOAT3PK` from three `float` arguments.

This constructor initializes a new instance of [XMFLOAT3PK](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmfloat3pk) from three
`float` arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_x`

Value to be stored in the x-component of the new instance of `XMFLOAT3PK`.

The value stored is transformed from the standard 32 floating point format (sign bit,
8 bit exponent, 23 bit mantissa), to an 11 bit floating point format (5 bit exponent,
6 bit mantissa).

### `_y`

Value to be stored in the y-component of the new instance of `XMFLOAT3PK`.

The value stored is transformed from the standard 32 floating point format (sign bit,
8 bit exponent, 23 bit mantissa), to an 11 bit floating point format (5 bit exponent,
6 bit mantissa). As the target format does not support a sign bit, **_y** must be
greater than zero.

### `_z`

Value to be stored in the x-component of the new instance of `XMFLOAT3PK`.

The value stored is transformed from the standard 32 floating point format (sign bit,
8 bit exponent, 23 bit mantissa), to a 10 bit floating point format (5 bit exponent,
5 bit mantissa). As the target format does not support a sign bit, **_z** must be
greater than zero.

## Remarks

As the floating point storage formats used by `XMFLOAT3PK` do not support a sign
bit, all arguments to this constructor must be greater than or equal to zero.

Because of the change in floating point format during the instantiation of an instance of
`XMFLOAT3PK`, some loss of precision can be expected.

## See also

**Reference**

[XMFLOAT3PK](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmfloat3pk)

[XMFLOAT3PK Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmfloat3pk-ctor)