# XMMATRIX structure

## Description

Describes a 4*4 matrix aligned on a 16-byte boundary that maps to four hardware vector registers.

DirectXMath uses row-major matrices, row vectors, and pre-multiplication. Handedness is determined by which function version is used (RH vs. LH).

For a list of additional functionality such as constructors and operators that are available using `XMMATRIX` when you
are programming in C++, see [XMMATRIX Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmmatrix-extensions).

**Note** See [DirectXMath Library Type Equivalences](https://learn.microsoft.com/windows/desktop/dxmath/pg-xnamath-internals) for information about
equivalent [D3DDECLTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddecltype), [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat), and
[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) objects.

## Members

### `_11`

### `_12`

### `_13`

### `_14`

### `_21`

### `_22`

### `_23`

### `_24`

### `_31`

### `_32`

### `_33`

### `_34`

### `_41`

### `_42`

### `_43`

### `_44`

### `m`

### `r`

Array of four vectors, representing the rows of the matrix.

### `operator=`

TBD

### `XMMATRIX`

TBD

### `operator()`

TBD

### `operator+=`

TBD

### `operator-=`

TBD

### `operator*=`

TBD

### `operator/=`

TBD

### `operator+`

TBD

### `operator-`

TBD

### `operator*`

TBD

### `operator/`

TBD

## Remarks

In the DirectXMath.h header file, the system uses an alias to the `XMMATRIX` object, specifically **CXMMATRIX**.
The header uses the alias to comply with the optimal in-line calling conventions of different compilers. For most
projects using DirectXMath it is sufficient to simply treat this as an exact alias to `XMMATRIX`.

Effectively:

```

typedef const XMMATRIX CXMMATRIX;

```

For projects that need detailed information about how different platform's calling conventions are handled, see
[Library Internals](https://learn.microsoft.com/windows/desktop/dxmath/pg-xnamath-internals).

`XMMATRIX` is row-major and all DirectXMath functions that accept an `XMMATRIX` as a parameter expect data to be organized as row-major.

Data in an `XMMATRIX` has the following layout.

```

_11 _12 _13 _14
_21 _22 _23 _24
_31 _32 _33 _34
_41 _42 _43 _44

```

DirectXMath defines **XMMATRIX** as a fully opaque type. To access individual elements of **XMMATRIX**, use equivalent types such as [XMFLOAT4](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat4) for a given row or [XMFLOAT4X4](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat4x4) for the whole matrix.

**Note** XNAMath 2.x defines `XMMATRIX` as a union with **_11** to **_44** members and an **m** array member. When you use these members of the union, poor performance results. DirectXMath.h still defines these `XMMATRIX` union members for when you build an app with [_XM_NO_INTRINSICS_](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-directives). XNAMath version 2.05 provides an opt-in XM_STRICT_XMMATRIX to enforce the DirectXMath behavior.

**Namespace:** Use DirectX

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMFLOAT4X4](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat4x4)

[XMMATRIX Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmmatrix-extensions)