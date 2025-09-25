# XMFLOAT3SE::XMFLOAT3SE(const float)

## Description

Initializes a new instance of [XMFLOAT3SE](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmfloat3se) from a three element `float` array argument.

This constructor initializes a new instance of **XMFLOAT3SE** from a from a three element float array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Three element floating point array containing the values used to initialize the three components of a new instance of **XMFLOAT3SE**.

## Remarks

Values contained in *pArray[0]*, *pArray[1]* and *pArray[2]* are stored, respectively, in the x-component, the y-component, and the z-component of the new instance of **XMFLOAT3SE**.

The values obtained from the members of *pArray* are transformed from the standard 32 bit floating point format (sign bit, 8 bit exponent, 23 bit mantissa), and stored as a 14 bit floating point format (5 bit exponent, 9 bit mantissa).

As no target formats do not support a sign bit, all member of *pArray* must be greater than zero.

Because of the change in floating point format during the instantiation of an instance of **XMFLOAT3SE** by this constructor, some loss of precision can be expected.

## See also

[XMFLOAT3SE](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmfloat3se)

[XMFLOAT3SE Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmfloat3se-ctor)