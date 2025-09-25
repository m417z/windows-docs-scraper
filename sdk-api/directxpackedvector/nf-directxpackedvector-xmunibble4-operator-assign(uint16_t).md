# XMUNIBBLE4::operator-assign(uint16_t)

## Description

Assigns the vector component data packed in an instance of `uint16_t` to the current
instance of `XMUNIBBLE4`.

**Note** This operator is only available under C++.

## Parameters

### `Packed`

The values of four vector components in a packed format.

## Return value

The current instance of `XMUNIBBLE4` whose vector component data has been
updated to the component values packed in the `uint16_t` instance specified
by the **Packed** argument.

## Remarks

The format of **Packed** is:

* The first 4 bits (bits 0-3) of **Packed** assigned to the **x** member of the current instance of `XMUNIBBLE4`.
* The second 4 bits (bits 4-7) of **Packed** assigned to the
  **y** member of the current instance of `XMUNIBBLE4`.
* The third 4 bits (bits 8-11) of **Packed** assigned to the **z** member of the current instance of `XMUNIBBLE4`.
* The last 4 bits (bits 12-15) of **Packed** assigned to the **w** member of the current instance of `XMUNIBBLE4`.

## See also

**Reference**

[XMUNIBBLE4](https://learn.microsoft.com/windows/win32/api/directxpackedvector/ns-directxpackedvector-xmunibble4)

[operator =](https://msdn.microsoft.com/03b4f870-696e-4719-8115-9becb307dd10)