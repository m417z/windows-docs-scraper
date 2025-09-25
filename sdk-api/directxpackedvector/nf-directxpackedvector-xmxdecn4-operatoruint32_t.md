# XMXDECN4::operator uint32_t

## Description

Returns an instance of `uint32_t` containing the components of the `XMXDECN4` instance in a packed format.

Returns an instance of `uint32_t` containing the components of the [XMXDECN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmxdecn4) instance in a packed format.

**Note** This operator is only available under C++.

## Return value

Contains the four vector components of an instance of `XMXDECN4` in a packed
format.

## Remarks

The values of the `XMXDECN4` components returned are not normalized, and are in
the following format:

* The first 10 bits (bits 0- 9) of the return value are the **x** component of the current instance of `XMXDECN4`.
* The second 10 bits (bits 10-19) of the return value are the **y** component of the current instance of `XMXDECN4`.
* The third 10 bits (bits 20-29) of the return value are the **z** component of the current instance of `XMXDECN4`.
* The last 2 bits (bits 30-31) of the return value are the **w** component
  of the current instance of `XMXDECN4`.

## See also

**Reference**

[XMXDECN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmxdecn4)

[XMXDECN4 Operators](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmxdecn4-operators)