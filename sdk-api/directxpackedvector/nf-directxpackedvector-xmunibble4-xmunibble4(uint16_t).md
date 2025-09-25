# XMUNIBBLE4::XMUNIBBLE4(uint16_t)

## Description

Initializes a new instance of `XMUNIBBLE` from a `uint16_t` variable
containing component data in a packed format.

This constructor initializes a new instance of [XMUNIBBLE4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmunibble4) from a
`uint16_t` variable containing component data in a packed format.

**Note** This constructor is only available under C++.

## Parameters

### `Packed`

The values of four vector components in a packed format.

## Remarks

The values defining the four components of the new instance of `XMUNIBBLE4` are
stored in the argument `Packed` as follows:

* The first 4 bits (bits 0-3) of **Packed** assigned, as an integer, to the
  **x** member of the instance of `XMUNIBBLE4` constructed.
* The second 4 bits (bits 4-7) of **Packed** assigned, as an integer, to
  the **y** member of the instance of `XMUNIBBLE4` constructed.
* The third 4 bits (bits 8-11) of **Packed** assigned, as an integer, to
  the **z** member of the instance of `XMUNIBBLE4` constructed.
* The last 4 bits (bits 12-15) of **Packed** assigned, as an integer, to
  the **w** member of the instance of `XMUNIBBLE4` constructed.

## See also

**Reference**

[XMUNIBBLE4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmunibble4)

[XMUNIBBLE4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmunibble4-ctor)