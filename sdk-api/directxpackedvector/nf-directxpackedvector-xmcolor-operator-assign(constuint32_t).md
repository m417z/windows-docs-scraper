# XMCOLOR::operator-assign(const uint32_t)

## Description

Assigns the vector component data packed in an instance of `uint32_t` to the current instance of
`XMCOLOR`.

This operator assigns the vector component data packed in an instance of `uint32_t` to the current instance of
[XMCOLOR](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmcolor).

**Note** This operator is only available under C++.

## Parameters

### `Color`

The values of four vector components in a packed format.

## Return value

The current instance of `XMCOLOR` whose vector component data has been
updated to the component values packed in the `uint32_t` instance specified by
the **Color** argument.

## Remarks

The format of **Color** is:

* The first 8 bits (bits 0-7) of **Color** assigned, as an unsigned integer, to the **a** member (alpha
  channel) of the current instance of `XMCOLOR`.
* The second 8 bits (bits 8-15) of **Color** assigned, as an unsigned integer, to the **r** member (red
  color channel) of the current instance of `XMCOLOR`.
* The third 8 bits (bits 16-23) of **Color** assigned, as an unsigned integer, to the **g** member (green
  color channel) of the current instance of `XMCOLOR`.
* The fourth 8 bits (bits 24-31) of **Color** assigned, as an unsigned integer, to the **b** member (blue
  color channel) of the current instance of `XMCOLOR`.

## See also

**Reference**

[XMCOLOR](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmcolor)

[operator =](https://msdn.microsoft.com/7dbba878-2f03-451f-b02b-75e531b6315b)