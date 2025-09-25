# XMFLOAT3PK::XMFLOAT3PK(uint32_t)

## Description

Initializes a new instance of `XMFLOAT3PK` from a `uint32_t` variable containing component data in a packed format.

This constructor initializes a new instance of [XMFLOAT3PK](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmfloat3pk) from a
`uint32_t` variable containing component data in a packed format.

**Note** This constructor is only available under C++.

## Parameters

### `Packed`

The values of three vector components in a packed format.

## Remarks

The values of the three components of the new instance of `XMFLOAT3PK` are stored
in the argument **Packed** with the z component (as a reduced precision
floating point number) in the most significant bits, and the x component is stored in the
least significant bits:

```

  (Z10Y11X11): [32] ZZZZZzzz zzYYYYYy yyyyXXX XXxxxxxx [0]

```

Or in detail:

* Bits 0-5 of **v** are the 6 bit *mantissa* of the
  **x** component's floating point value: the **xm** member of new instance of the structure.
* Bits 6-10 of **v** are the 5 bit *exponent* of the
  **x** component's floating point value the **xe** member of new instance of the structure.
* Bits 11-16 of **v** are the 6-bit *mantissa* of the
  **y** component's floating point value: the **ym** member of new instance of the structure.
* Bits 17-21 of **v** are the 5 bit *exponent* of the
  **y** component's floating point value: the **ye** member of new instance of the structure.
* Bits 22-26 of **v** are the 5 bit *mantissa* of the
  **z** component's floating point value: the **zm** member of new instance of the structure.
* Bits 27-31 of **v** are the 5 bit *exponent* of the
  **z** component's floating point value: the **ze** member of new instance of the structure.

## See also

**Reference**

[XMFLOAT3PK](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmfloat3pk)

[XMFLOAT3PK Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmfloat3pk-ctor)