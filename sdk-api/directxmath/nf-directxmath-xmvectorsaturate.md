# XMVectorSaturate function

## Description

Saturates each component of a vector to the range 0.0f to 1.0f.

## Parameters

### `V` [in]

Vector to saturate.

## Return value

Returns a vector, each of whose components are saturated.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
XMVECTOR Result;

Result.x = min(max(V1.x, 0.0f), 1.0f);
Result.y = min(max(V1.y, 0.0f), 1.0f);
Result.z = min(max(V1.z, 0.0f), 1.0f);
Result.w = min(max(V1.w, 0.0f), 1.0f);

return Result;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Vector Arithmetic Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-arithmetic)