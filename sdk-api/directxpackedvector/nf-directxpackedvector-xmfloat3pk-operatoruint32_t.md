# XMFLOAT3PK::operator uint32_t

## Description

Returns an instance of `uint32_t` containing the components of the
`XMFLOAT3PK` instance in a packed format.

This operator returns an instance of `uint32_t` containing the components of the
[XMFLOAT3PK](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmfloat3pk) instance in a packed format.

**Note** This operator is only available under C++.

## Return value

Contains the three vector components of an instance of
`XMFLOAT3PK` in a packed format.

## Remarks

The values of the three components of the current instance of `XMFLOAT3PK` are
returned packed in a `uint32_t` with the z component (as a reduced precision floating
point number) in the most significant bits, and the x component is stored in the least
significant bits:

```

  (Z10Y11X11): [32] ZZZZZzzz zzYYYYYY yyyyyXXX XXXxxxxx [0]

```

Or in detail:

* Bits 0-5 of the return value are the 6 bit *mantissa* of the
  **x** component's floating point value.
* Bits 6-10 of the return value are the 5 bit *exponent* of the
  **x** component's floating point value.
* Bits 11-16 of the return value are the 6-bit *mantissa* of the
  **y** component's floating point value.
* Bits 17-21 of the return value are the 5 bit *exponent* of the
  **y** component's floating point value.
* Bits 22-26 of the return value are the 5 bit *mantissa* of the
  **z** component's floating point value.
* Bits 27-31 of the return value are the 5 bit *exponent* of the
  **z** component's floating point value.

## See also

**Reference**

[XMFLOAT3PK](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmfloat3pk)

[XMFLOAT3PK Operators](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmfloat3pk-operators)