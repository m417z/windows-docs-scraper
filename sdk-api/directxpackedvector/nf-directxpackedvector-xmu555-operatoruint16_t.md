# XMU555::operator uint16_t

## Description

Returns an instance of `uint16_t` containing the components of the
`XMU555` instance in a packed format.

This operator returns an instance of `uint16_t` containing the components of the [XMU555](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmu555)  instance in a packed format.

**Note** This operator is only available under C++.

## Return value

Contains the four vector components of an instance of `XMU555` in a packed
format.

## Remarks

The packed format of this operators return value is:

* The first 5 bits (bits 0-4) of the return value are to the **x** component of the current instance of `XMU555`.
* The second 5 bits (bits 5-9) of the return value are to the **y** component of the current instance of `XMU555`.
* The third 5 bits (bits 10-14) of the return value are to the **z** component of the current instance of `XMU555`.
* The last 1 bit (bit 15) of the return value are to the **w** component of the current instance of `XMU555`.

## See also

**Reference**

[XMU555](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmu555)

[XMU555 Operators](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmu555-operators)