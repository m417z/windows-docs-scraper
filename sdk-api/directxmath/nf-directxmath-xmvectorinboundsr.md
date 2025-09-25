# XMVectorInBoundsR function

## Description

Tests whether the components of a given vector are within certain bounds and sets a comparison value that can be examined using functions such as [XMComparisonAllTrue](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmcomparisonalltrue).

## Parameters

### `pCR` [out]

Pointer to a **uint32_t** comparison value that can be examined using functions such as [XMComparisonAllInBounds](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmcomparisonallinbounds). The `XMComparisonXXXX` functions may be used to further test the number of components that passed the comparison.

### `V` [in]

Vector to test.

### `Bounds` [in]

Vector that determines the bounds.

## Return value

Returns a vector containing the results of each component test.

## Remarks

The following pseudocode demonstrates the comparison operation of the function:

```
XMVECTOR Control;

Control.x = (V.x <= Bounds.x && V.x >= -Bounds.x) ? 0xFFFFFFFF : 0;
Control.y = (V.y <= Bounds.y && V.y >= -Bounds.y) ? 0xFFFFFFFF : 0;
Control.z = (V.z <= Bounds.z && V.z >= -Bounds.z) ? 0xFFFFFFFF : 0;
Control.w = (V.w <= Bounds.w && V.w >= -Bounds.w) ? 0xFFFFFFFF : 0;

return Control;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Geometric Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-geometric)

[XMVectorInBounds](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorinbounds)