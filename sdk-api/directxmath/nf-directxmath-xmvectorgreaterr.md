# XMVectorGreaterR function

## Description

Performs a per-component test for greater-than between two vectors and sets a comparison value that can be examined using functions such as [XMComparisonAllTrue](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmcomparisonalltrue).

## Parameters

### `pCR` [out]

Pointer to a **uint32_t** comparison value that can be examined using functions such as [XMComparisonAllTrue](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmcomparisonalltrue). The `XMComparisonXXXX` functions may be used to further test the number of components that passed the comparison.

### `V1` [in]

First vector to compare.

### `V2` [in]

Second vector to compare.

## Return value

Returns a vector containing the results of each component test.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Vector Comparison Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-comparison)

[XMVectorGreater](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorgreater)