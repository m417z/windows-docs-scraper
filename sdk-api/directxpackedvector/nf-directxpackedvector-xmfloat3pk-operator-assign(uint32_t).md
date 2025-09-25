# XMFLOAT3PK::operator-assign(uint32_t)

## Description

This operator assigns the vector component data packed in an instance of `uint32_t` to
the current instance of [XMFLOAT3PK](https://learn.microsoft.com/windows/win32/api/directxpackedvector/ns-directxpackedvector-xmfloat3pk).

**Note** This operator is only available under C++.

## Parameters

### `Packed`

The values of three vector components in a packed format.

## Return value

The current instance of `XMFLOAT3PK` whose vector component data has been updated to
the component values packed in the `uint32_t` instance specified by the
**Packed** argument.

## Remarks

The values of the three components assigned to the current instance of `XMFLOAT3PK` are stored
in the argument **Packed** with the z component (as a reduced precision
floating point number) in the most significant bits, and the x component is stored in the
least significant bits:

|  |
| --- |
| ```   (Z10Y11X11): [32] ZZZZZzzz zzYYYYYy yyyyyXXX XXxxxxxx [0] ``` |

Or in detail:

* Bits 0-5 of **v** are the 6 bit *mantissa* of the
  **x** component's floating point value: the **xm** member of the current structure.
* Bits 6-10 of **v** are the 5 bit *exponent* of the
  **x** component's floating point value the **xe** member of the current structure.
* Bits 11-16 of **v** are the 6-bit *mantissa* of the
  **y** component's floating point value: the **ym** member of the current structure.
* Bits 17-21 of **v** are the 5 bit *exponent* of the
  **y** component's floating point value: the **ye** member of the current structure.
* Bits 22-26 of **v** are the 5 bit *mantissa* of the
  **z** component's floating point value: the **zm** member of the current structure.
* Bits 27-31 of **v** are the 5 bit *exponent* of the
  **z** component's floating point value: the **ze** member of the current structure.

## See also

**Reference**

[XMFLOAT3PK](https://learn.microsoft.com/windows/win32/api/directxpackedvector/ns-directxpackedvector-xmfloat3pk)

[operator =](https://msdn.microsoft.com/82c6ee72-0706-49f9-bc19-9725496440d0)