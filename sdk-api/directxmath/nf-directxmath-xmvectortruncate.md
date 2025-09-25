# XMVectorTruncate function

## Description

Rounds each component of a vector to the nearest integer value in the direction of zero.

## Parameters

### `V` [in]

Vector whose components are to be truncated.

## Return value

Returns a vector whose components are rounded to the nearest integer value in the direction of zero.

## Remarks

The return value is computed based on the following logic, which preserves special values (INF,+INF,NaN,-NaN).

```

Result[0] = (fabsf(V[0]) < 8388608.0f) ? ((float)((int32_t)V[0])) : V[0];
Result[1] = (fabsf(V[1]) < 8388608.0f) ? ((float)((int32_t)V[1])) : V[1];
Result[2] = (fabsf(V[2]) < 8388608.0f) ? ((float)((int32_t)V[2])) : V[2];
Result[3] = (fabsf(V[3]) < 8388608.0f) ? ((float)((int32_t)V[3])) : V[3];

```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Vector Arithmetic Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-arithmetic)