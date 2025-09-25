# XMFLOAT3PK::XMFLOAT3PK(const float)

## Description

Initializes a new instance of [XMFLOAT3PK](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmfloat3pk) from a three element `float` array argument.

This constructor initializes a new instance of **XMFLOAT3PK** from a three element `float` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Three element floating point array containing the values used to initialize the three components of a new instance of **XMFLOAT3PK**.

## Remarks

Values contained in *pArray[0]* and *pArray[1]* are stored, respectively, in the x-component and the y-component of the new instance of **XMFLOAT3PK**.

The values obtained from *pArray[0]* and *pArray[1]* are transformed from the standard 32 bit floating point format (sign bit, 8 bit exponent, 23 bit mantissa), and stored as an 11 bit floating point format (5 bit exponent, 6 bit mantissa).

Value contained in *pArray[2]* is stored, in the Z-component the new instance of **XMFLOAT3PK**.
The value obtained from *pArray[2]* is transformed from the standard 32-bit floating point format (sign bit, 8 bit exponent, 23 bit mantissa), and stored as a 10 bit floating point format (5 bit exponent, 5 bit mantissa).

As no target formats do not support a sign bit, all member of *pArray* must be greater than zero.

Because of the change in floating point format during the instantiation of an instance of **XMFLOAT3PK** by this constructor, some loss of precision can be expected.

## See also

[XMFLOAT3PK](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmfloat3pk)

[XMFLOAT3PK Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmfloat3pk-ctor)