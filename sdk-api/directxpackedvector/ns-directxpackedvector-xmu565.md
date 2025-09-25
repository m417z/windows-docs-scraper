## Description

A 3D vector with x- and z- components represented as 5-bit unsigned integer values,
and the y- component as a 6-bit unsigned integer value.

For a list of more functionality such as constructors and operators that are available
using `XMU565` when you are programming in C++, see [XMU565 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmu565-extensions).

## Members

### `v`

Unsigned short representing the 3D vector.

### `x` : 5

The 5-bit x component.

### `y` : 6

The 5-bit y component.

### `z` : 5

The 5-bit z component.

## Remarks

You can use [XMLoadU565](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmloadu565) to load `XMU565` into instances
of  [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

You can use [XMStoreU565](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmstoreu565) to store instances of `XMVECTOR`
into an instance of `XMU565`.

**Namespace:** Use DirectX::PackedVector

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMU565 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmu565-extensions)