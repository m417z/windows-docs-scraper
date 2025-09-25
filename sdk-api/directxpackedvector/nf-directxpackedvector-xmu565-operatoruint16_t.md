# XMU565::operator uint16_t

## Description

Returns an instance of `uint16_t` containing the components of the `XMU555` instance in a packed format.

This operator returns an instance of `uint16_t` containing the components of the [XMU555](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmu555)  instance in a packed format.

**Note** This operator is only available under C++.

## Return value

Contains the three vector components of an instance of `XMU555` in a packed
format.

## Remarks

The packed format of this operators return value is:

* The first 5 bits (bits 0-4) of the return value are to the **x** component of the current instance of `XMU555`.
* The second 6 bits (bits 5-10) of the return value are to the **y** component of the current instance of `XMU555`.
* The third 5 bits (bits 11-15) of the return value are to the **z** component of the current instance of `XMU555`.

## See also

**Reference**

[XMU565](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmu565)

[XMU565 Operators](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmu565-operators)