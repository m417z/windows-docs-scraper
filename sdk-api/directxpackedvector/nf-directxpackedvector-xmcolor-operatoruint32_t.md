# XMCOLOR::operator uint32_t

## Description

Returns an instance of `uint32_t` containing the components of the `XMCOLOR` instance in a packed format.

**Note** This operator is only available under C++.

## Return value

Contains the four color channel value components of an instance of
`XMCOLOR` in a packed format.

## Remarks

The values of the `XMCOLOR` color channels components returned are not
normalized, and are in the following format:

* The first 8 bits (bits 0-7) of the return value are the **a** member (alpha
  channel) of the current instance of `XMCOLOR`.
* The second 8 bits (bits 8-15) of the return value are the **r** member (red
  color channel) of the current instance of `XMCOLOR`.
* The third 8 bits (bits 16-23) of the return value are the **g** member (green
  color channel) of the current instance of `XMCOLOR`.
* The fourth 8 bits (bits 24-31) of the return value are the **b** member (blue
  color channel) of the current instance of `XMCOLOR`.

## See also

**Reference**

[XMCOLOR](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmcolor)

[XMCOLOR Operators](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmcolor-operators)