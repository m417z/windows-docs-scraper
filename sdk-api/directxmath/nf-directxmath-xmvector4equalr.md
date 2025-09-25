# XMVector4EqualR function

## Description

Tests whether two 4D vectors are equal. In addition, this function returns a comparison value that can be examined using functions such as [XMComparisonAllTrue](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmcomparisonalltrue).

## Parameters

### `V1` [in]

4D vector.

### `V2` [in]

4D vector.

## Return value

Returns a comparison value that can be examined using functions such as [XMComparisonAllTrue](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmcomparisonalltrue).

## Remarks

This function does the following test:

```
V1.x == V2.x
V1.y == V2.y
V1.z == V2.z
V1.w == V2.w
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 4D Vector Comparison Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector4-comparison)

[XMVector4Equal](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector4equal)