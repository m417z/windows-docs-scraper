# XMCOLOR::XMCOLOR(uint32_t)

## Description

Initializes a new instance of `XMCOLOR` from a `uint32_t` variable containing
component data in a packed format.

This constructor initializes a new instance of [XMCOLOR](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmcolor) from a
`uint32_t` variable containing component data in a packed format.

**Note** This constructor is only available under C++.

## Parameters

### `Color`

The values of four color components in a packed format.

## Remarks

The values defining the four components of the new instance of `XMCOLOR` are
stored in the argument `Packed` as follows:

* The first 8 bits (bits 0-7) of **Packed** assigned, as an unsigned
  integer, to the **a** member (alpha channel) of the instance of
  `XMCOLOR` constructed.
* The second 8 bits (bits 8-15) of **Packed** assigned, as an unsigned
  integer, to the **r** member (red color channel) of the instance of
  `XMCOLOR` constructed.
* The third 8 bits (bits 16-23) of **Packed** assigned, as an unsigned
  integer, to the **g** member (green color channel) of the instance of
  `XMCOLOR` constructed.
* The fourth 8 bits (bits 24-31) of **Packed** assigned, as an unsigned
  integer, to the **b** member (blue color channel) of the instance of
  `XMCOLOR` constructed.

## See also

**Reference**

[XMCOLOR](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmcolor)

[XMCOLOR Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmcolor-ctor)