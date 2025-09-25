# XMUBYTEN4::XMUBYTEN4(uint32_t)

## Description

Initializes a new instance of `XMUBYTEN4` from a `uint32_t` variable containing component data in a packed format.

This constructor initializes a new instance of [XMUBYTEN4](https://msdn.microsoft.com/552002c1-0000-44a6-9f43-9c958a8d1aa3) from a
`uint32_t` variable containing component data in a packed format.

**Note** This constructor is only available under C++.

## Parameters

### `Packed`

The values of four vector components of the new instance, in a packed format.

## Remarks

The values defining the three components of the new instance of `XMUBYTEN4` are
not normalized, and are stored in the argument `Packed` in the following
format:

* The first 8 bits (bits 0-7) of **Packed** assigned, as an unsigned
  integer, to the **x** member of the instance of `XMUBYTEN4` constructed.
* The second 8 bits (bits 8-15) of **Packed** assigned, as an unsigned
  integer, to the **y** member of the instance of `XMUBYTEN4` constructed.
* The third 8 bits (bits 16-23) of **Packed** assigned, as an unsigned
  integer, to the **z** member of the instance of `XMUBYTEN4` constructed.
* The last 8 bits (bits 24-31) of **Packed** assigned, as an unsigned
  integer, to the **w** member of the instance of `XMUBYTEN4` constructed.

## See also

**Reference**

[XMUBYTEN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmubyten4)

[XMUBYTEN4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmubyten4-ctor)