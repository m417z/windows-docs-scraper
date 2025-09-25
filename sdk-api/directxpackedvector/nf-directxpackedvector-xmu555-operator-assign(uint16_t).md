# XMU555::operator-assign(uint16_t)

## Description

Assigns the vector component data packed in an instance of `uint16_t` to the current
instance of `XMU555`.

Assigns the vector component data packed in an instance of `uint16_t` to the current
instance of [XMU555](https://learn.microsoft.com/windows/win32/api/directxpackedvector/ns-directxpackedvector-xmu555).

**Note** This operator is only available under C++.

## Parameters

### `Packed`

The values of four vector components in a packed format.

## Return value

 The current instance of `XMU555` whose
vector component data has been updated to the component values packed in the
`uint16_t` instance specified by the **Packed** argument.

## Remarks

The format of **Packed** is:

* The first 5 bits (bits 0-4) of **Packed** assigned to the **x** member of the current instance of `XMU555`.
* The second 5 bits (bits 5-9) of **Packed** assigned to the
  **y** member of the current instance of `XMU555`.
* The third 5 bits (bits 10-14) of **Packed** assigned to the **z** member of the current instance of `XMU555`.
* The last 1 bits (bit 15) of **Packed** assigned to the **w** member of the current instance of `XMU555`.

## See also

**Reference**

[XMU555](https://learn.microsoft.com/windows/win32/api/directxpackedvector/ns-directxpackedvector-xmu555)

[operator =](https://msdn.microsoft.com/f2deb13c-c389-461e-aba7-2520b454d46e)