# XMU565::XMU565(uint16_t)

## Description

Initializes a new instance of `XMU565` from a `uint16_t` variable containing
component data in a packed format.

This constructor initializes a new instance of [XMU565](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmu565) from a
`uint16_t` variable containing component data in a packed format.

**Note** This constructor is only available under C++.

## Parameters

### `Packed`

 The values of three vector components in a packed format.

## Remarks

The values defining the three components of the new instance of `XMU565` are
stored in the argument `Packed` as follows:

* The first 5 bits (bits 0-4) of **Packed** assigned, as an integer, to the
  **x** member of the instance of `XMU565` constructed.
* The second 6 bits (bits 5-10) of **Packed** assigned, as an integer, to
  the **y** member of the instance of `XMU565` constructed.
* The third 5 bits (bits 11-15) of **Packed** assigned, as an integer, to
  the **z** member of the instance of `XMU565` constructed.

## See also

**Reference**

[XMU565](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmu565)

[XMU565 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmu565-ctor)