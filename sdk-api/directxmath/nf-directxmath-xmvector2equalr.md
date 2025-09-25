# XMVector2EqualR function

## Description

Tests whether two 2D vectors are equal. In addition, this function returns a comparison value that can be examined using functions such as [XMComparisonAllTrue](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmcomparisonalltrue).

## Parameters

### `V1` [in]

2D vector.

### `V2` [in]

2D vector.

## Return value

Returns a comparison value that can be examined using functions such as [XMComparisonAllTrue](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmcomparisonalltrue).

## Remarks

This function does the following test:

```
V1.x == V2.x
V1.y == V2.y
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 2D Vector Comparison Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector2-comparison)

[XMVector2Equal](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector2equal)