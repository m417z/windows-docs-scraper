# XMFLOAT3SE::operator uint32_t

## Description

Returns an instance of `uint32_t` containing the components of the
`XMFLOAT3SE` instance in a packed format.

This operator returns an instance of `uint32_t` containing the components of the
[XMFLOAT3SE](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmfloat3se) instance in a packed format.

**Note** This operator is only available under C++.

## Return value

Contains the three vector components of an instance of `XMFLOAT3SE` in a packed format.

## Remarks

The values of the three components of the current instance of `XMFLOAT3SE` are
returned in the following format: the **e** member of the `XMFLOAT3SE` structure -- the exponent shared by the mantissas of the floating point values of all
three components of `XMFLOAT3SE` -- is stored in the highest order bits of the
return value, and the mantissa of the x component stored in the least significant bits.

```

   (E5Z9Y9X9): [32] EEEEEzzz zzzzzzyy yyyyyyyx xxxxxxxx [0]

```

Or in detail:

* Bits 0-8 of the return value are the 9 bit *mantissa* of the
  **x** component's floating point value: the **xm** member of the current structure.
* Bits 9-17 of the return value are the 9 bit *mantissa* of the
  **y** component's floating point value: the **ym** member of the current structure.
* Bits 18-26 of the return value are the 9 bit *mantissa* of the
  **z** component's floating point value: the **zm** member of the current structure.
* Bits 27-31 of the return value are the 5 bit *exponent* used
  with the stored mantissas (**xm**, **ym**,
  **zm**) to represent the size of each component: the **e** member of the current structure.

## See also

**Reference**

[XMFLOAT3SE](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmfloat3se)

[XMFLOAT3SE Operators](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmfloat3se-operators)