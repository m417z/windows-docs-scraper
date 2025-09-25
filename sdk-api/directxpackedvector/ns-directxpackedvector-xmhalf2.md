# XMHALF2 structure

## Description

A 2D vector consisting of two half-precision (16bit) floating-point values.

For a list of additional functionality such as constructors and operators that are available
using `XMHALF2` when you are programming in C++, see [XMHALF2 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmhalf2-extensions).

**Note** See [DirectXMath Library Type
Equivalences](https://learn.microsoft.com/windows/desktop/dxmath/pg-xnamath-internals) for information about equivalent [D3DDECLTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddecltype), [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat), and [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) objects.

## Members

### `x`

**HALF** value describing the x-coordinate.

### `y`

**HALF** value describing the y-coordinate.

### `v`

### `XMHALF2`

TBD

### `operator=`

TBD

## Remarks

The definition of the `HALF` type used under DirectXMath is consistent with the [IEEE
standard](https://ieeexplore.ieee.org/xpl/freeabs_all.jsp?arnumber=4610935), and consists of a sign bit, a 5 bit biased exponent, and a 10 bit
mantissa:

```

                    [15] SEEEEEMMMMMMMMMM [0]
	
```

`XMHALF2` can be loaded into instances of [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) by using [XMLoadHalf2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmloadhalf2).

Instances of `XMVECTOR` can be stored into an instance of `XMHALF2` with [XMStoreHalf2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmstorehalf2).

**Namespace:** Use DirectX::PackedVector

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMHALF2 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmhalf2-extensions)