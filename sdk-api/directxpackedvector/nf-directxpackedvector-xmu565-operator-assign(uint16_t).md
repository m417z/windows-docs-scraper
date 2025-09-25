# XMU565::operator-assign(uint16_t)

## Description

Assigns the vector component data packed in an instance of `uint16_t` to the current
instance of `XMU565`.

Assigns the vector component data packed in an instance of `uint16_t` to the current
instance of [XMU565](https://learn.microsoft.com/windows/win32/api/directxpackedvector/ns-directxpackedvector-xmu565).

**Note** This operator is only available under C++.

## Parameters

### `Packed`

The values of three vector components in a packed format.

## Return value

The current instance of `XMU565` whose vector component data has been
updated to the component values packed in the `uint16_t` instance specified
by the **Packed** argument.

## Remarks

The format of **Packed** is:

* The first 5 bits (bits 0-4) of **Packed** assigned to the **x** member of the current instance of `XMU565`.
* The second 6 bits (bits 5-10) of **Packed** assigned to the **y** member of the current instance of `XMU565`.
* The third 5 bits (bits 11-15) of **Packed** assigned to the **z** member of the current instance of `XMU565`.

## See also

**Reference**

[XMU565](https://learn.microsoft.com/windows/win32/api/directxpackedvector/ns-directxpackedvector-xmu565)

[operator =](https://msdn.microsoft.com/05e80a7b-107a-4355-a057-3315cdf46844)