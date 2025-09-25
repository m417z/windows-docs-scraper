## Description

Describes a 3D vector of three floating-point components with 9 bit mantissas, each sharing
the same 5-bit exponent.

For a list of additional functionality such as constructors and operators that are available
using `XMFLOAT3SE` when you are programming in C++, see [XMFLOAT3SE Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmfloat3se-extensions).

## Members

### `v`

Unsigned 32-bit integer representing the 3D vector.

### `e` : 5

The 5-bit shared exponent.

### `xm` : 9

The 9-bit x component.

### `ym` : 9

The 9-bit y component.

### `zm` : 9

The 9-bit z component.

## Remarks

The values of the three components of an instance of `XMFLOAT3SE` are stored in
the **v** of the instance in the following format: the **e** member of the
`XMFLOAT3SE` structure -- the exponent shared by the mantissas of the
floating point values of all three components of `XMFLOAT3SE` -- is
stored in the highest order bits of the return value, and the mantissa of the x
component stored in the least significant bits.

```

   (E5Z9Y9X9): [31] EEEEEzzz zzzzzzyy yyyyyyyx xxxxxxxx [0]

```

Or in detail:

* Bits 0-8 of **Packed** are the 9 bit *mantissa* of the
  **x** component's floating point value: the **xm** member of the current
  structure.
* Bits 9-17 of **Packed** are the 9 bit *mantissa* of the
  **y** component's floating point value: the **ym** member of the current
  structure.
* Bits 18-26 of **Packed** are the 9 bit *mantissa* of the
  **z** component's floating point value: the **zm** member of the current
  structure.
* Bits 27-31 of **Packed** are the 5 bit *exponent* used with
  the stored mantissas (**xm**, **ym**, **zm**) to represent the size
  of each component: the **e** member of the current structure.

As there are no sign bits in the format for storing the components in the `XMFLOAT3SE` structure, all component values are positive.

`XMFLOAT3SE` can be loaded into instances of [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) by using [XMLoadFloat3SE](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmloadfloat3se).

Instances of `XMVECTOR` can be stored into an instance of `XMFLOAT3SE` with [XMStoreFloat3SE](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmstorefloat3se).

**Namespace:** Use DirectX::PackedVector

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMFLOAT3SE Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmfloat3se-extensions)