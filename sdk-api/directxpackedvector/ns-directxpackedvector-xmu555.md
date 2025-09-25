## Description

A 4D vector with x-,y-, and z- components represented as 5 bit unsigned integer values, and
the w-component as a 1 bit integer value.

For a list of additional functionality such as constructors and operators that are available
using `XMU555` when you are programming in C++, see [XMU555 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmu555-extensions).

## Members

### `v`

Unsigned short representing the 4D vector.

### `w` : 1

A 1-bit integer value in the range [0,31] describing the w-coordinate of
the vector.

### `x` : 5

Unsigned 5-bit integer value in the range [0,31] describing the
x-coordinate of the vector.

### `y` : 5

Unsigned 5-bit integer value in the range [0,31] describing the
y-coordinate of the vector.

### `z` : 5

Unsigned 5-bit integer value in the range [0,31] describing the
z-coordinate of the vector.

## Remarks

`XMU555` can be loaded into instances of  [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) by
using [XMLoadU555](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmloadu555).

Instances of `XMVECTOR` can be stored into an instance of `XMU555` with [XMStoreU555](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmstoreu555).

**Namespace:** Use DirectX::PackedVector

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMU555 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmu555-extensions)