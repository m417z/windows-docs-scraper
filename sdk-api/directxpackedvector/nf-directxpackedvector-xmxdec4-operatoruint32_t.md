# XMXDEC4::operator uint32_t

## Description

Returns an instance of `uint32_t` containing the components of the `XMXDEC4` instance in a packed format.

This operator returns an instance of `uint32_t` containing the components of the [XMXDEC4](https://msdn.microsoft.com/5b46e0fb-e4a5-49c4-8084-0c631d43d4f7) instance in a packed format.

**Note** This operator is only available under C++.

## Return value

Contains the four vector components of an instance of `XMXDEC4` in a packed
format.

## Remarks

The packed format of this operators return value is:

* The first 20 bits (bits 0-09) of the return value are to the **x** component of the current instance of `XMXDEC4`.
* The second 20 bits (bits 10-19) of the return value are to the **y** component of the current instance of `XMXDEC4`.
* The third 20 bits (bits 20-29) of the return value are to the **z** component of the current instance of `XMXDEC4`.
* The last 4 bits (bits 30-31) of the return value are to the **w** component of the current instance of `XMXDEC4`.

## See also

**Reference**

[XMXDEC4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmxdec4)

[XMXDEC4 Operators](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmxdec4-operators)