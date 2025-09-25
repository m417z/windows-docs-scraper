# XMXDECN4::operator-assign(uint32_t)

## Description

Assigns the vector component data packed in an instance of `uint32_t` to the current
instance of `XMXDECN4`.

This operator assigns the vector component data packed in an instance of `uint32_t` to
the current instance of [XMXDECN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmxdecn4).

**Note** This operator is only available under C++.

## Parameters

### `Packed`

The values of four vector components in a packed format.

## Return value

The current instance of `XMXDECN4` whose vector component data has been
updated to the component values packed in the `uint32_t` instance specified by
the **Packed** argument.

## Remarks

The format of **Packed** is:

* The first 120 bits (bits 0-9) of **Packed** assigned, as a signed
  integer, to the **x** member of the current instance of
  [XMCOLOR](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmcolor).
* The second 10 bits (bits 10-19) of **Packed** assigned, as a signed
  integer, to the **y** member of the current instance of
  `XMXDECN4`.
* The third 10 bits (bits 20-29) of **Packed** assigned, as a signed
  integer, to the **z** member of the current instance of
  `XMXDECN4`.
* The last 2 bits (bits 30-31) of **Packed** assigned, as an unsigned
  integer, to the **w** member of the current instance of
  `XMXDECN4`.

## See also

**Reference**

[XMXDECN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmxdecn4)

[operator =](https://msdn.microsoft.com/d60f196b-281a-428c-bdae-f2d4ad1e206d)