# XMBYTE4::XMBYTE4(uint32_t)

## Description

Initializes a new instance of `XMBYTE4` from a `uint32_t` variable containing component data in a packed format.

This constructor initializes a new instance of [XMBYTE4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmbyte4) from a
`uint32_t` variable containing component data in a packed format.

**Note** This constructor is only available under C++.

## Parameters

### `Packed`

The values of four vector components of the new instance, in a packed format.

## Remarks

The values of the four components of the new instance of `XMBYTE4` are stored in the
argument `Packed` as follows:

* The first 8 bits (bits 0-7) of **Packed** assigned, as an unsigned integer, to the **x** member of the instance of `XMBYTE4` constructed.
* The second 8 bits (bits 8-15) of **Packed** assigned, as an unsigned integer, to the **y** member of the instance of `XMBYTE4` constructed.
* The third 8 bits (bits 16-23) of **Packed** assigned, as an unsigned
  integer, to the **z** member of the instance of `XMBYTE4` constructed.
* The last 8 bits (bits 24-31) of **Packed** assigned, as an unsigned integer, to the **w** member of the instance of `XMBYTE4` constructed.

## See also

**Reference**

[XMBYTE4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmbyte4)

[XMBYTE4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmbyte4-ctor)