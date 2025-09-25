## Description

A 4D vector with four unsigned 4-bit integer components.

For a list of additional functionality such as constructors and operators that are available
using `XMUNIBBLE4` when you are programming in C++, see [XMUNIBBLE4 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmunibble4-extensions).

## Members

### `v`

Unsigned short representing the 4D vector in a packed format.

### `w` : 4

Unsigned 4-bit integer value in the range [0,15] describing the
w-coordinate of the vector. The 4-bit x component.

### `x` : 4

Unsigned 4-bit integer value in the range [0,15] describing the
x-coordinate of the vector. The 4-bit x component.

### `y` : 4

Unsigned 4-bit integer value in the range [0,15] describing the
y-coordinate of the vector. The 4-bit x component.

### `z` : 4

Unsigned 4-bit integer value in the range [0,15] describing the
z-coordinate of the vector. The 4-bit x component.

## Remarks

`XMUNIBBLE4` can be loaded into instances of [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) by using
[XMLoadUNibble4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmloadunibble4).

Instances of `XMVECTOR` can be stored into an instance of `XMUNIBBLE4` with [XMStoreUNibble4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmstoreunibble4).

**Namespace:** Use DirectX::PackedVector

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMUNIBBLE4 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmunibble4-extensions)