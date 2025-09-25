# XMUBYTE4::XMUBYTE4(uint32_t)

## Description

Initializes a new instance of [XMUBYTE4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmubyte4) from a `Uuint32_t` variable containing component data in a packed format.

This constructor initializes a new instance of **XMUBYTE4** from a `Uuint32_t` variable containing component data in a packed format.

**Note** This constructor is only available under C++.

## Parameters

### `Packed`

The values of four vector components of the new instance, in a packed format.

## Remarks

The values of the four components of the new instance of **XMUBYTE4* are stored in the argument *Packed* as follows:

* The first 8 bits (bits 0-7) of *Packed* assigned, as a signed integer, to the **x** member of the instance of **XMUBYTE4** constructed.
* The second 8 bits (bits 8-15) of *Packed* assigned, as a signed integer, to the **y** member of the instance of **XMUBYTE4** constructed.
* The third 8 bits (bits 16-23) of *Packed* assigned, as a signed integer, to the **z** member of the instance of **XMUBYTE4** constructed.
* The last 8 bits (bits 24-31) of *Packed* assigned, as a signed integer, to the **w** member of the instance of **XMUBYTE4** constructed.

## See also

[XMUBYTE4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmubyte4)

[XMUBYTE4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmubyte4-ctor)