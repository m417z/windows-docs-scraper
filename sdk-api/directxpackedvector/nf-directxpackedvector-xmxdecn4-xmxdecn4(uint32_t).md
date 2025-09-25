# XMXDECN4::XMXDECN4(uint32_t)

## Description

Initializes a new instance of `XMXDECN4` from a `uint32_t` variable containing
component data in a packed format.

This constructor initializes a new instance of [XMXDECN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmxdecn4)  from a
`uint32_t` variable containing component data in a packed format.

**Note** This constructor is only available under C++.

## Parameters

### `Packed`

The values of four vector components in a packed format.

## Remarks

The values defining the four components of the new instance of `XMXDECN4` are
not normalized and are stored in the argument `Packed` as follows:

* The first 10 bits (bits 0-9) of **Packed** assigned, as a signed
  integer, to the **x** member of the instance of `XMXDECN4` constructed.
* The second 10 bits (bits 10-19) of **Packed** assigned, as a signed
  integer, to the **y** member of the instance of `XMXDECN4` constructed.
* The third 10 bits (bits 20-29) of **Packed** assigned, as a signed
  integer, to the **z** member of the instance of `XMXDECN4` constructed.
* The last 2 bits (bits 30-31) of **Packed** assigned, as an unsigned
  integer, to the **w** member of the instance of `XMXDECN4` constructed.

## See also

**Reference**

[XMXDECN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmxdecn4)

[XMXDECN4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmxdecn4-ctor)