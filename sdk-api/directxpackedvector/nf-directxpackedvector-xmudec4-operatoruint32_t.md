# XMUDEC4::operator uint32_t

## Description

Returns an instance of `uint32_t` containing the components of the `XMUDEC4` instance in a packed format.

This operator returns an instance of `uint32_t` containing the components of the [XMUDEC4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmudec4) instance in a packed format.

**Note** This operator is only available under C++.

## Return value

Contains the four vector components of an instance of `XMUDEC4` in a packed
format.

## Remarks

The packed format of this operators return value is:

* The first 20 bits (bits 0-09) of the return value are to the **x** component of the current instance of `XMUDEC4`.
* The second 20 bits (bits 10-19) of the return value are to the **y** component of the current instance of `XMUDEC4`.
* The third 20 bits (bits 20-29) of the return value are to the **z** component of the current instance of `XMUDEC4`.
* The last 4 bits (bits 30-31) of the return value are to the **w** component of the current instance of `XMUDEC4`.

## See also

**Reference**

[XMUDEC4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmudec4)

[XMUDEC4 Operators](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmudec4-operators)