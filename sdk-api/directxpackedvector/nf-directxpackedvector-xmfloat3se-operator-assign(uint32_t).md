# XMFLOAT3SE::operator-assign(uint32_t)

## Description

This operator assigns the vector component data packed in an instance of `uint32_t` to
the current instance of [XMFLOAT3SE](https://learn.microsoft.com/windows/win32/api/directxpackedvector/ns-directxpackedvector-xmfloat3se).

**Note** This operator is only available under C++.

## Parameters

### `Packed`

The values of three vector components in a packed format.

## Return value

The current instance of `XMFLOAT3SE` whose vector component data has been updated to
the component values packed in the `uint32_t` instance specified by the
**Packed** argument.

## Remarks

The values of the three components of the updated current instance of `XMFLOAT3SE` are loaded from the argument **Packed**. The format of these data have the
**e** member of the `XMFLOAT3SE` structure -- the exponent shared by the
mantissas of the floating point values of all three stored components -- is stored in the highest order
bits of **Packed**, and the mantissa of the x component stored in the least significant bits.

|  |
| --- |
| ```    (E5Z9Y9X9): [32] EEEEEzzz zzzzzzyy yyyyyyyx xxxxxxxx [0] ``` |

Or in detail:

* Bits 0-8 of **Packed** are the 9 bit *mantissa* of the
  **x** component's floating point value: the **xm** member of the current structure.
* Bits 9-17 of **Packed** are the 9 bit *mantissa* of the
  **y** component's floating point value: the **ym** member of the current structure.
* Bits 18-26 of **Packed** are the 9 bit *mantissa* of the
  **z** component's floating point value: the **zm** member of the current structure.
* Bits 27-31 of **Packed** are the 5 bit *exponent* used
  with the stored mantissas (**xm**, **ym**,
  **zm**) to represent the size of each component: the **e** member of the current structure.

## See also

**Reference**

[XMFLOAT3SE](https://learn.microsoft.com/windows/win32/api/directxpackedvector/ns-directxpackedvector-xmfloat3se)

[operator =](https://msdn.microsoft.com/e3c74a38-65ab-48ac-931d-1fc66ec04d74)