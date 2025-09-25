# XMVectorClamp function

## Description

Clamps the components of a vector to a specified minimum and maximum range.

## Parameters

### `V` [in]

Vector whose components are to be clamped.

### `Min` [in]

Minimum range vector.

### `Max` [in]

Maximum range vector.

## Return value

Returns a vector whose components are clamped to the specified minimum and maximum values.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
XMVECTOR Result;

Result.x = min( max( V.x, Min.x ), Max.x );
Result.y = min( max( V.y, Min.y ), Max.y );
Result.z = min( max( V.z, Min.z ), Max.z );
Result.w = min( max( V.w, Min.w ), Max.w );

return Result;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Vector Arithmetic Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-arithmetic)