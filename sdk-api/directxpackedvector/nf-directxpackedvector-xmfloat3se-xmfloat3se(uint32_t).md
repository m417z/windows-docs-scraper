# XMFLOAT3SE::XMFLOAT3SE(uint32_t)

## Description

Initializes a new instance of `XMFLOAT3SE` from a `uint32_t` variable containing component data in a packed format.

This constructor initializes a new instance of [XMFLOAT3SE](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmfloat3se) from a
`uint32_t` variable containing component data in a packed format.

**Note** This constructor is only available under C++.

## Parameters

### `Packed`

The values of three vector components in a packed format.

## Remarks

The values of the three components of the new instance of `XMFLOAT3SE` are stored
in the argument **Packed** with the exponent shared by all the mantissas of the floating point values
of all three components (the **e** of the `XMFLOAT3SE` structure) stored in
the highest order bits, and the mantissa of the x component stored in the least
significant bits.

```

   (E5Z9Y9X9): [32] EEEEEzzz zzzzzzyy yyyyyyyx xxxxxxxx [0]

```

Or in detail:

* Bits 0-8 of **Packed** are the 9 bit *mantissa* of the
  **x** component's floating point value: the **xm** member of the
  structure to be instantiated.
* Bits 9-17 of **Packed** are the 9 bit *mantissa* of the
  **y** component's floating point value: the **ym** member of the
  structure to be instantiated.
* Bits 18-26 of **Packed** are the 9 bit *mantissa* of the
  **z** component's floating point value: the **zm** member of the
  structure to be instantiated.
* Bits 27-31 of **Packed** are the 5 bit *exponent* used
  with the stored mantissas (**xm**, **ym**, **zm**) to represent
  the size of each component: the **e** member of the structure to be
  instantiated.

## See also

**Reference**

[XMFLOAT3SE](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmfloat3se)

[XMFLOAT3SE Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmfloat3se-ctor)