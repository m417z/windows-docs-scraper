# XMUNIBBLE4::operator uint16_t

## Description

Returns an instance of `uint16_t` containing the components of the
`XMUNIBBLE4` instance in a packed format.

This operator returns an instance of `uint16_t` containing the components of the [XMUNIBBLE4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmunibble4)  instance in a packed format.

**Note** This operator is only available under C++.

## Return value

Contains the four vector components of an instance of `XMUNIBBLE4` in a packed
format.

## Remarks

The packed format of this operators return value is:

* The first 4 bits (bits 0-3) of the return value are to the **x** component of the current instance of `XMUNIBBLE4`.
* The second 4 bits (bits 4-7) of the return value are to the **y** component of the current instance of `XMUNIBBLE4`.
* The third 4 bits (bits 8-11) of the return value are to the **z** component of the current instance of `XMUNIBBLE4`.
* The last 4 bits (bits 12-15) of the return value are to the **w** component of the current instance of `XMUNIBBLE4`.

## See also

**Reference**

[XMUNIBBLE4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmunibble4)

[XMUNIBBLE4 Operators](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmunibble4-operators)