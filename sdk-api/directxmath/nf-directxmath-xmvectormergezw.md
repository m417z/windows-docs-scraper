# XMVectorMergeZW function

## Description

Creates a new vector by combining the z and w-components of two vectors.

## Parameters

### `V1` [in]

First vector.

### `V2` [in]

Second vector.

## Return value

Returns the merged vector.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
XMVECTOR Result;

Result.x = V1.z;
Result.y = V2.z;
Result.z = V1.w;
Result.w = V2.w;

return Result;

```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Component-Wise Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-component-wise)

[XMVectorMergeXY](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectormergexy)