# XMBYTEN4::XMBYTEN4(uint32_t)

## Description

Initializes a new instance of `XMBYTEN4` from a `uint32_t` variable containing component data in a packed format.

This constructor initializes a new instance of [XMBYTEN4](https://msdn.microsoft.com/62d61a35-8674-4855-b09c-f351363cd50b) from a
`uint32_t` variable containing component data in a packed format.

**Note** This constructor is only available under C++.

## Parameters

### `Packed`

The values of four vector components of the new instance, in a packed format.

## Remarks

The values defining the three components of the new instance of `XMBYTEN4` are
not normalized, and are stored in the argument `Packed` in the following
format:

* The first 8 bits (bits 0-7) of **Packed** assigned, as a signed
  integer, to the **x** member of the instance of `XMBYTEN4` constructed.
* The second 8 bits (bits 8-15) of **Packed** assigned, as a signed
  integer, to the **y** member of the instance of `XMBYTEN4` constructed.
* The third 8 bits (bits 16-23) of **Packed** assigned, as a signed
  integer, to the **z** member of the instance of `XMBYTEN4` constructed.
* The last 8 bits (bits 24-31) of **Packed** assigned, as a signed
  integer, to the **w** member of the instance of `XMBYTEN4` constructed.

## See also

**Reference**

[XMBYTEN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmbyten4)

[XMBYTEN4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmbyten4-ctor)