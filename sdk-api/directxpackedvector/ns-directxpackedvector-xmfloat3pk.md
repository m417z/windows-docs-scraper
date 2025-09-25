## Description

Describes a 3D vector with X and Y components stored as 11 bit floating point number, and Z
component stored as a 10 bit floating-point value.

For a list of additional functionality, such as constructors and operators, available using
`XMFLOAT3PK` when programming in C++, see [XMFLOAT3PK Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmfloat3pk-extensions).

## Members

### `v`

Unsigned 32-bit integer representing the 3D vector.

### `xe` : 5

The 5-bit biased exponent for the x component.

### `xm` : 6

The 6-bit mantissa for the x component.

### `ye` : 5

The 5-bit biased exponent for the y component.

### `ym` : 6

The 6-bit mantissa for the y component.

### `ze` : 5

The 5-bit biased exponent for the z component.

### `zm` : 5

The 5-bit mantissa for the z component.

## Remarks

There are no sign bits. This means all partial-precision numbers are positive. The z
component is stored in the most significant bits, and the x component is stored in the
least significant bits like this:

```
(Z10Y11X11): [31] ZZZZZzzz zzYYYYYy yyyyyXXX XXxxxxxx [0]
```

Or in detail:

* Bits 0-5 of **v** are the 6 bit *mantissa* of the **x** component's floating point value: the **xm** member of the structure.
* Bits 6-10 of **v** are the 5 bit *exponent* of the
  **x** component's floating point value the **xe** member of the structure.
* Bits 11-16 of **v** are the 6-bit *mantissa* of the
  **y** component's floating point value: the **ym** member of the
  structure.
* Bits 17-21 of **v** are the 5 bit *exponent* of the
  **y** component's floating point value: the **ye** member of the
  structure.
* Bits 22-26 of **v** are the 5 bit *mantissa* of the
  **z** component's floating point value: the **zm** member of the
  structure.
* Bits 27-31 of **v** are the 5 bit *exponent* of the
  **z** component's floating point value: the **ze** member of the
  structure.

`XMFLOAT3PK` can be loaded into instances of  [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) by using [XMLoadFloat3PK](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmloadfloat3pk).

Instances of `XMVECTOR` can be stored into an instance of `XMFLOAT3PK` with [XMStoreFloat3PK](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmstorefloat3pk).

MIN_F10 / MIN_F11 = 6.10352e-5

MAX_F10 = 64512

MAX_F11 = 65024

**Namespace:** Use DirectX::PackedVector

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMFLOAT3PK Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmfloat3pk-extensions)