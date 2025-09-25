# XMUDEC4::XMUDEC4(uint32_t)

## Description

Initializes a new instance of `XMUDEC4` from a `uint32_t` variable containing
component data in a packed format.

This constructor initializes a new instance of [XMUDEC4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmudec4) from a
`uint32_t` variable containing component data in a packed format.

**Note** This constructor is only available under C++.

## Parameters

### `Packed`

The values of the four components of the new instance of `XMUDEC4` are
stored in the argument `Packed` as follows:

## Remarks

The values of the four components of the new instance of `XMUDEC4` are stored in
the argument `Packed` as follows:

* The first 10 bits (bits 0-9) of **Packed** assigned, as an unsigned integer, to
  the **x** member of the instance of `XMUDEC4` constructed.
* The second 10 bits (bits 10-19) of **Packed** assigned, as an unsigned integer, to
  the **y** member of the instance of `XMUDEC4` constructed.
* The third 10 bits (bits 20-29) of **Packed** assigned, as an unsigned integer, to
  the **z** member of the instance of `XMUDEC4` constructed.
* The last 2 bits (bits 30-31) of **Packed** assigned, as an unsigned integer, to
  the **w** member of the instance of `XMUDEC4` constructed.

## See also

**Reference**

[XMUDEC4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmudec4)

[XMUDEC4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmudec4-ctor)