# XMDECN4::operator-assign(uint32_t)

## Description

This operator assigns the vector component data packed in an instance of `uint32_t` to the current instance of [XMDECN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmdecn4).

**Note** This operator is only available under C++.

## Parameters

### `Packed`

The values of four vector components in a packed format.

## Return value

The current instance of `XMDECN4` whose vector component data has been
updated to the component values packed in the `uint32_t` instance specified by
the **Packed** argument.

## Remarks

The format of **Packed** is:

* The first 120 bits (bits 0-9) of **Packed** assigned, as an integer, to
  the **x** member of the current instance of [XMCOLOR](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmcolor).
* The second 10 bits (bits 10-19) of **Packed** assigned, as an integer, to
  the **y** member of the current instance of [XMDECN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmdecn4).
* The third 10 bits (bits 20-29) of **Packed** assigned, as an integer, to
  the **z** member of the current instance of [XMDECN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmdecn4).
* The last 2 bits (bits 30-31) of **Packed** assigned, as an integer, to
  the **w** member of the current instance of [XMDECN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmdecn4).

## See also

**Reference**

[XMDECN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmdecn4)

[operator =](https://msdn.microsoft.com/9a3af6a8-d53f-41c2-bd95-9ec2e2b02b7b)