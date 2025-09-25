# XMU555::XMU555(uint16_t)

## Description

Initializes a new instance of `XMU555` from a `uint16_t` variable containing
component data in a packed format.

This constructor initializes a new instance of [XMU555](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmu555) from a
`uint16_t` variable containing component data in a packed format.

**Note** This constructor is only available under C++.

## Parameters

### `Packed`

The values of four vector components in a packed format.

## Remarks

The values defining the four components of the new instance of `XMU555` are
stored in the argument `Packed` as follows:

* The first 5 bits (bits 0-4) of **Packed** assigned, as an integer, to the
  **x** member of the instance of `XMU555` constructed.
* The second 5 bits (bits 5-9) of **Packed** assigned, as an integer, to
  the **y** member of the instance of `XMU555` constructed.
* The third 5 bits (bits 10-14) of **Packed** assigned, as an integer, to
  the **z** member of the instance of `XMU555` constructed.
* The last 1 bits (bit 15) of **Packed** assigned, as an integer, to
  the **w** member of the instance of `XMU555` constructed.

## See also

**Reference**

[XMU555](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmu555)

[XMU555 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmu555-ctor)